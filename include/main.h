#define WINDOW_X 800
#define WINDOW_Y 600
#define WINDOW_RATIO (float)WINDOW_X/(float)WINDOW_Y

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

// This determines how much does a keypress moves the camera
#define C_KEY_STRENGTH 10

#include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <sys/time.h>

typedef struct s_vec3 {
	float x;
	float y;
	float z;
} t_vec3;

// Sphere is defined by the center point and the radius
typedef struct s_sphere
{
	t_vec3	pos;
	float	r;
} t_sphere;

// Camera is defined by a bunch of stuff i dont understand
typedef struct s_camera {
    t_vec3	pos;
    t_vec3	forward; // normalized direction vector
    t_vec3	right; // perpendicular to forward & up
    t_vec3	up; // camera's up direction
    int		fov; // in degrees
} t_camera;

typedef struct s_minilib_interface
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*first_pixel;
	int				pixel_depth;
	int				size_line;
	int				endian;

} t_minilib;

typedef struct s_app
{
	// t_minilib minilib;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*first_pixel;
	int				pixel_depth;
	int				size_line;
	int				endian;

	struct timeval	time;

	t_camera		global_cam;
	// pointeur a la camera

	// liste des objets a dessiner

	// liste des lumieres

	// lumiere ambiante
}	t_app;
