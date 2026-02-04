// basique:
// soit un espace xyz.
// on place une camera au point xyz oriente vers xyz.
// il y a un plan (de meme resolution que l'ecran) place a une certaine distance de la camera (FOV)
// alors, pour chaque pixel de l'ecran, on project un rayon partant de la camera
// qui passe par le meme point sur le plan
// et lorsqu'il rencontre un objet: ce pixel est de la couleur de l'objet

// Pour chaque pixel de l'ecran:
// faire une equation (pour chaque object) qui verifie la collision
// dessiner le pixel.

#include "../include/main.h"

t_sphere g_s = {{0,0,100}, 10};

//  ██████████   ███████████     █████████   █████   ███   █████
// ░░███░░░░███ ░░███░░░░░███   ███░░░░░███ ░░███   ░███  ░░███ 
//  ░███   ░░███ ░███    ░███  ░███    ░███  ░███   ░███   ░███ 
//  ░███    ░███ ░██████████   ░███████████  ░███   ░███   ░███ 
//  ░███    ░███ ░███░░░░░███  ░███░░░░░███  ░░███  █████  ███  
//  ░███    ███  ░███    ░███  ░███    ░███   ░░░█████░█████░   
//  ██████████   █████   █████ █████   █████    ░░███ ░░███     
// ░░░░░░░░░░   ░░░░░   ░░░░░ ░░░░░   ░░░░░      ░░░   ░░░      

// Change the memory value in the image
void	set_image_pixel_at(t_app *app, int x, int y, int color)
{
	int	*buffer;
	int	bytes_per_pixel;

	bytes_per_pixel = app->pixel_depth / 8;
	buffer = (int *)app->first_pixel;
	buffer[(y * app->size_line / bytes_per_pixel) + x] = color;
}

//  ██████   ██████   █████████   ███████████ █████   █████        
// ░░██████ ██████   ███░░░░░███ ░█░░░███░░░█░░███   ░░███         
//  ░███░█████░███  ░███    ░███ ░   ░███  ░  ░███    ░███   █████ 
//  ░███░░███ ░███  ░███████████     ░███     ░███████████  ███░░  
//  ░███ ░░░  ░███  ░███░░░░░███     ░███     ░███░░░░░███ ░░█████ 
//  ░███      ░███  ░███    ░███     ░███     ░███    ░███  ░░░░███
//  █████     █████ █████   █████    █████    █████   █████ ██████ 
// ░░░░░     ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░   ░░░░░ ░░░░░░  
            
#include <math.h>

// Returns the dot product of two vectors
float dot_product(t_vec3 a, t_vec3 b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

// Given a camera and a pixel position, returns D
// D is the normalized directional vector from the camera to the pixel at z=1
t_vec3	get_direction_vector(t_camera camera, int pixel_x, int pixel_y)
{
	// Build ray for pixel (x,y) in camera space using FOV
	// + 0.5f mean it's the center of the pixel
	float ndc_x = (2.0f * (pixel_x + 0.5f) / (float)WINDOW_X) - 1.0f; // -1..1
	float ndc_y = 1.0f - (2.0f * (pixel_y + 0.5f) / (float)WINDOW_Y); // 1..-1 (flip y)q
	float aspect = (float)WINDOW_X / (float)WINDOW_Y;

	// Correct implementation of FOV -> scaling for rays, though i dont
	// really understand it. TODO
	float fov_rad = camera.fov * (M_PI / 180.0f);
	float scale = tanf(fov_rad * 0.5f);

	// My naive implementation
	// float scale = (float)app->global_cam.fov/100;

	/* Point on the image plane at z = 1 in camera space */
	float px = ndc_x * aspect * scale;
	float py = ndc_y * scale;

	// Rotate the points so that it matches the rotation of the camera.
	// Ray direction in world space: px*right + py*up + pz*forward
	// pz = 1 here:
	t_vec3 D = (t_vec3){
		px * camera.right.x + py * camera.up.x + camera.forward.x,
		px * camera.right.y + py * camera.up.y + camera.forward.y,
		px * camera.right.z + py * camera.up.z + camera.forward.z
	};

	/* normalize D */
	float len = sqrtf(dot_product(D, D));
	if (len != 0.0f)
		D.x /= len; D.y /= len; D.z /= len;

	return (D);
}


// A - B
t_vec3 vec3_minus_op(t_vec3 a, t_vec3 b)
{
	return ((t_vec3) {a.x - b.x, a.y - b.y, a.z - b.z});
}

// Given a sphere, a camera and the pixel to draw
// Find the closest point t 
float	calc_ray_x_sphere(t_app *app, int x, int y, t_sphere sphere)
{
	int		color;

	float a;
	float b;
	float c;
	float discriminant;

	t_vec3 origin_of_ray = app->global_cam.pos;
	t_vec3 D = get_direction_vector(app->global_cam, x, y); // D est le vecteur directeur du rayon
	t_vec3 L; // L est le vecteur du centre de la sphere a la camera
	/* L = O - C */
	L = vec3_minus_op(origin_of_ray, sphere.pos);

	a = dot_product(D, D);
	b = 2.0f * dot_product(D, L);
	c = dot_product(L, L) - sphere.r * sphere.r;
	discriminant = b * b - 4.0f * a * c;
	// If Δ<0: no intersection
	// If Δ=0: one intersection (tangent)
	// If Δ>0: two intersections

	// If Δ>=0: compute roots and accept nearest positive t */
	if (discriminant >= 0.0f)
	{
		float sqrt_d = sqrtf(discriminant);
		float t0 = (-b - sqrt_d) / (2.0f * a);
		float t1 = (-b + sqrt_d) / (2.0f * a);
		/* choose nearest positive t */
		float closest;
		closest = -1.0f;
		if (t0 > 0.0f)
			closest = t0;
		if (t1 > 0.0f && (closest < 0.0f || t1 < closest))
			closest = t1;
		return ((float) closest);
	}
	return (-1.0f);
}

int	calc_raytrace(t_app *app, int x, int y)
{
	float	intersection;

	intersection = calc_ray_x_sphere(app, x, y, g_s);
	int color = 0;
	if (intersection >= 0.0f) {
		int shade = (int)fmax(0, 255 - (int)(intersection * 0.4f));
		color = (shade << 16) | (shade << 8) | shade; // gray
	}
	return (color);
}

// redraw the image
void redraw(t_app *app)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while(++x < WINDOW_X)
	{
		y = -1;
		while(++y < WINDOW_Y)
		{
			color = calc_raytrace(app, x, y);
			set_image_pixel_at(app, x, y, color);
		}
	}
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}


// Whenever a malloc fail, we exit and free everything
int	exit_n_clean(t_app *app)
{
	if (!app)
		return (0);
	if (app->mlx_ptr && app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	if (app->mlx_ptr && app->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img_ptr);
	if (app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
	}
	free(app);
	exit(0);
	return (0);
}

// Create the window
t_app	*create_app(void)
{
	t_app	*app;
	char	*p;
	char	*(*f)(void *, int *, int *, int *);

	app = malloc(sizeof(t_app));
	if (!app)
		return (NULL);
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
		exit_n_clean(app);
	app->win_ptr = mlx_new_window(app->mlx_ptr, WINDOW_X, WINDOW_Y, "YAAAAAAY");
	app->img_ptr = mlx_new_image(app->mlx_ptr, WINDOW_X, WINDOW_Y);
	if (!app->img_ptr || !app->win_ptr)
		exit_n_clean(app);
	if (gettimeofday(&app->time, NULL) == -1)
		exit_n_clean(app);
	f = mlx_get_data_addr;
	p = f(app->img_ptr, &app->pixel_depth, &app->size_line, &app->endian);
	app->first_pixel = p;
	if (!app->first_pixel)
		exit_n_clean(app);

	// init objects
	app->global_cam = (t_camera){{0,0,0}, {0,0,1}, {1,0,0}, {0,1,0}, 70};
	return (app);
}

//  █████   █████    ███████       ███████    █████   ████  █████████ 
// ▒▒███   ▒▒███   ███▒▒▒▒▒███   ███▒▒▒▒▒███ ▒▒███   ███▒  ███▒▒▒▒▒███
//  ▒███    ▒███  ███     ▒▒███ ███     ▒▒███ ▒███  ███   ▒███    ▒▒▒ 
//  ▒███████████ ▒███      ▒███▒███      ▒███ ▒███████    ▒▒█████████ 
//  ▒███▒▒▒▒▒███ ▒███      ▒███▒███      ▒███ ▒███▒▒███    ▒▒▒▒▒▒▒▒███
//  ▒███    ▒███ ▒▒███     ███ ▒▒███     ███  ▒███ ▒▒███   ███    ▒███
//  █████   █████ ▒▒▒███████▒   ▒▒▒███████▒   █████ ▒▒████▒▒█████████ 
// ▒▒▒▒▒   ▒▒▒▒▒    ▒▒▒▒▒▒▒       ▒▒▒▒▒▒▒    ▒▒▒▒▒   ▒▒▒▒  ▒▒▒▒▒▒▒▒▒  
                                                   
// keycodes (X11)
# define ESC_KEY		65307
# define NUMPAD_PLUS	65451
# define NUMPAD_MINUS	65453
# define KEY_R			114
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100

# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_UP		65362
# define KEY_ARROW_RIGHT	65363
# define KEY_ARROW_DOWN		65364

// numpad keys
# define NUMPAD_0		65438
# define NUMPAD_1		65436
# define NUMPAD_2		65433
# define NUMPAD_3		65435
# define NUMPAD_4		65430
# define NUMPAD_5		65437
# define NUMPAD_6		65432
# define NUMPAD_7		65429
# define NUMPAD_DIV		65455
# define NUMPAD_MUL		65450
// mouse buttons
# define MOUSE_LEFT		1
# define MOUSE_MIDDLE	2
# define MOUSE_RIGHT	3
# define MOUSE_WHEEL_UP	4
# define MOUSE_WHEEL_DN	5

#include <stdio.h>

void print_cam(t_app *app)
{
	printf("pos: %f %f %f ", app->global_cam.pos.x, app->global_cam.pos.y, app->global_cam.pos.z);
	printf("fov: %i \n", app->global_cam.fov);
}

int	on_mouse_input(int keycode, int mouse_x, int mouse_y, t_app *app)
{
	if (keycode == MOUSE_WHEEL_UP)
		app->global_cam.fov += 10;
	else if (keycode == MOUSE_WHEEL_DN)
		app->global_cam.fov -= 10;
	else if (keycode == MOUSE_LEFT)
		printf("sphere: %f %f %f \n", g_s.pos.x, g_s.pos.y, g_s.pos.z);
	else
		printf("got %i key input \n", keycode);
	redraw(app);
	print_cam(app);
	return (0);
}

int	on_no_input(t_app *app)
{
	return (0);
}

// This determines how much does a keypress moves the camera
#define C_KEY_STRENGTH 10

int	on_key_input(int keycode, t_app	*app)
{
	if (keycode == ESC_KEY)
		exit_n_clean(app);
	printf("got %i key input \n", keycode);
	if (keycode == KEY_W)
		app->global_cam.pos.z += C_KEY_STRENGTH;
	else if (keycode == KEY_S)
		app->global_cam.pos.z -= C_KEY_STRENGTH;
	else if (keycode == KEY_A)
		app->global_cam.pos.x -= C_KEY_STRENGTH * WINDOW_RATIO;
	else if (keycode == KEY_D)
		app->global_cam.pos.x += C_KEY_STRENGTH * WINDOW_RATIO;

	else if (keycode == KEY_ARROW_UP)
		app->global_cam.pos.y += C_KEY_STRENGTH;
	else if (keycode == KEY_ARROW_DOWN)
		app->global_cam.pos.y -= C_KEY_STRENGTH;
	else if (keycode == KEY_ARROW_LEFT)
		app->global_cam.pos.x -= C_KEY_STRENGTH * WINDOW_RATIO;
	else if (keycode == KEY_ARROW_RIGHT)
		app->global_cam.pos.x += C_KEY_STRENGTH * WINDOW_RATIO;
	print_cam(app);
	redraw(app);
	return (0);
	
}

int main(void)
{
	t_app	*app;

	app = create_app();
	if (!app)
		return (-1);
	mlx_key_hook (app->win_ptr, on_key_input, app);
	mlx_mouse_hook (app->win_ptr, on_mouse_input, app);
	mlx_loop_hook(app->mlx_ptr, on_no_input, app);
	mlx_hook(app->win_ptr, 17, 0, exit_n_clean, app);
	printf("cc\n");
	redraw(app);
	mlx_loop(app->mlx_ptr);
}