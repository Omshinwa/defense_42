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

t_sphere g_s = {{1,1,1}, 2};

t_camera g_cam = {
	{0,0,0},
	{0,0,1},
	{1,0,0},
	{0,1,0},
	70
};

// Change the memory value in the image
void	set_image_pixel_at(t_app *app, int x, int y, int color)
{
	int	*buffer;
	int	bytes_per_pixel;

	bytes_per_pixel = app->pixel_depth / 8;
	buffer = (int *)app->first_pixel;
	buffer[(y * app->size_line / bytes_per_pixel) + x] = color;
}

float dot_product(t_vec3 a, t_vec3 b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

int	calc_collision_sphere(t_app *app, int x, int y, t_sphere sphere)
{
	int		color;

	float a;
	float b;
	float c;
	float discriminant;

	t_vec3 origin_of_ray; // POSITION of origin of ray
	t_vec3 L; // L est le vecteur du centre de la sphere a la camera
	t_vec3 D = g_cam.forward; // D est le vecteur directeur du rayon
	origin_of_ray = g_cam.pos;
	origin_of_ray.x += x/1000;
	origin_of_ray.y += y/1000;
	L = (t_vec3){sphere.pos.x - g_cam.pos.x, sphere.pos.y - g_cam.pos.y, sphere.pos.z - g_cam.pos.z};
	a=1;
	b=2*dot_product(D, L);
	c=dot_product(L,L) - sphere.r * sphere.r;
	discriminant = b*b - 4 * a * c;
	// If Δ<0: no intersection
	// If Δ=0: one intersection (tangent)
	// If Δ>0: two intersections
	if (discriminant>=0)
		return (454545);
	
	return (0);
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
			color = calc_collision_sphere(app, x, y, g_s);
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
	return (app);
}

//  █████   █████                   █████             
// ▒▒███   ▒▒███                   ▒▒███              
//  ▒███    ▒███   ██████   ██████  ▒███ █████  █████ 
//  ▒███████████  ███▒▒███ ███▒▒███ ▒███▒▒███  ███▒▒  
//  ▒███▒▒▒▒▒███ ▒███ ▒███▒███ ▒███ ▒██████▒  ▒▒█████ 
//  ▒███    ▒███ ▒███ ▒███▒███ ▒███ ▒███▒▒███  ▒▒▒▒███
//  █████   █████▒▒██████ ▒▒██████  ████ █████ ██████ 
// ▒▒▒▒▒   ▒▒▒▒▒  ▒▒▒▒▒▒   ▒▒▒▒▒▒  ▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒▒  
                                                   
// keycodes (X11)
# define ESC_KEY		65307
# define ARROW_LEFT		65361
# define ARROW_UP		65362
# define ARROW_RIGHT	65363
# define ARROW_DOWN		65364
# define NUMPAD_PLUS	65451
# define NUMPAD_MINUS	65453
# define R_KEY			114
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

int	on_mouse_input(int keycode, int mouse_x, int mouse_y, t_app *app)
{
	return (0);
}

int	on_no_input(t_app *app)
{
	return (0);
}

int	on_key_input(int keycode, t_app	*app)
{
	if (keycode == ESC_KEY)
		exit_n_clean(app);
	return (0);
}

#include <stdio.h>
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