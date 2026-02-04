#define WINDOW_X 800
#define WINDOW_Y 600
#define WINDOW_RATIO (float)WINDOW_X/(float)WINDOW_Y


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
