#include "so_long.h"
#include <stdio.h>
#include <mlx.h>
// // #define X 50
// // #define Y 50
// // #define PI 3.14
// // typedef struct s_data
// // {
// // 	void *img;
// // 	char *addr;
// // 	int bits_per_pixel;
// // 	int line_length;
// // 	int endian;
// // } t_data;
// // void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// // {
// // 	char *dst;
// // 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// // 	*(unsigned int *)dst = color;
// // }
// // int main()
// // {
// // 	void *mlx;
// // 	void *mlx_win;
// // 	t_data img;
// // 	float x = 0;
// // 	float y = 0;
// // 	int color;
// // 	color = 255;
// // 	mlx = mlx_init();
// // 	mlx_win = mlx_new_window(mlx, 950, 672, "hello world!");
// // 	img.img = mlx_new_image(mlx, 950, 672);
// // 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// // 	for (float theta = 0; theta < 2 * PI; theta += 0.01) {
// // 		x = 100 + 80 * cos(theta);
// // 		y = 100 + 80 * sin(theta);
// // 		// color = color + 1;
// // 		my_mlx_pixel_put(&img, x, y, color);
// // 	}
// // 	mlx_put_image_to_window(&img, mlx_win, img.img, 0, 0);
// // 	mlx_loop(mlx);
// // }
// // #include <stdio.h>
// // int main()
// // {
// // 	printf("%d\n", 7 & 3);
// // }
// // #include <mlx.h>
// // #include <stdlib.h>
// // typedef struct	s_vars {
// // 	void	*mlx;
// // 	void	*win;
// // }				t_vars;
// // int	close(int keycode, t_vars *vars)
// // {
// // 	printf("Key pressed: %d\n", keycode);
// // 	if (keycode == 53) // ESC key
// // 	{
// // 		mlx_destroy_window(vars->mlx, vars->win);
// // 		exit(0);
// // 	}
// // 	return (0);
// // }
// // int	resize(int x, int y, t_vars *vars)
// // {
// // 	(void)x;
// // 	(void)y;
// // 	printf("Window resized\n");
// // 	return (0);
// // }
// // int	close_window(t_vars *vars)
// // {
// // 	printf("Window closed\n");
// // 	exit(0);
// // 	return (0);
// // }
// // int keypress_s(int keycode, t_vars *vars)
// // {
// // 	int i ;
// // 	i = 1000;
// // 	while (keycode && i != 0)
// // 		i--;
// // 	printf("i: %d\n", i);
// // 	return 0;
// // }
// // int	main(void)
// // {
// // 	t_vars	vars;
// // 	vars.mlx = mlx_init();
// // 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// // 	mlx_hook(vars.win, 2, 1L<<0, keypress_s, &vars); // KeyPress event
// // 	mlx_hook(vars.win, 4, 1L<<0, resize, &vars); // ConfigureNotify event
// // 	mlx_hook(vars.win, 17, 1L<<17, close_window, &vars); // CloseNotify event
// // 	mlx_loop(vars.mlx);
// // }
// // #include <mlx.h>
// // #include <stdio.h>
// // int main(void)
// // {
// // 	void *mlx;
// // 	void *win;
// // 	void *img;
// // 	int x;
// // 	int y;
// // 	x = 0;
// // 	y = 0;
// // 	mlx = mlx_init();
// // 	win = mlx_new_window(mlx, 800, 600, "map");
// // 	// img = mlx_new_image(mlx, 800, 600);
// // 	// while (y < 600)
// // 	// {
// // 	// 	x = 0 ;
// // 	// 	while (x < 800)
// // 	// 	{
// // 	// 		if (x % 2 == 0)
// // 	// 			mlx_pixel_put(mlx, win, x, y, 0x000000FF);
// // 	// 		else
// // 	// 			mlx_pixel_put(mlx, win, x, y, 0x0000FF00);
// // 	// 		x++;
// // 	// 	}
// // 	// 	y++;
// // 	// }
// // 	int width, height;
// // 	img = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
// // 	mlx_put_image_to_window(mlx, win, img, 0, 0);
// // 	img = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
// // 	mlx_put_image_to_window(mlx, win, img, 32, 0);
// // 	// mlx_xpm_to_image(mlx,  , 32, 32);
// // 	mlx_loop_hook();
// // 	return 0;
// // }

// typedef struct s_pa
// {
// 	void *mlx;
// 	void *win;
// } t_pa;
// typedef struct s_ima
// {
// 	void *img_ptr;
// 	char *addr;
// 	int bits_per_pixel;
// 	int size_line;
// 	int endian;
// } t_ima;
// int display_str(int button, int x, int y, void *parm)
// {
// 	t_pa *param = (t_pa *)parm;
// 	if (button)
// 	{
// 		mlx_string_put(param->mlx, param->win, 50, 30, 255, "button");
// 		printf("button:%d\n", button);
// 	}
// 	if (x)
// 	{
// 		mlx_string_put(param->mlx, param->win, 40, 50, 255, "x");
// 		printf("x:%d\n",x);
// 	}
// 	if (y)
// 	{
// 		mlx_string_put(param->mlx, param->win, 80, 90, 255, "y");
// 		printf("y:%d\n",y);
// 	}
// 	return (0);
// }
// int print_str(void *parm)
// {
// 	t_pa *param = (t_pa *)parm;
// 	mlx_string_put(param->mlx, param->win, 10, 100, 255, "AHHH");
// 	return (0);
// }
// void	my_mlx_pixel_put(t_ima *data, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
// int main()
// {
// 	t_pa param;
// 	t_ima img;
// 	param.mlx = mlx_init();
// 	param.win = mlx_new_window(param.mlx, 500, 500, "test");
// 	img.img_ptr = mlx_new_image(param.mlx, 500, 500);
// 	mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
// 	// img.addr = img.addr + ();
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(param.mlx, param.win, img.img_ptr, 0, 0);
// 	// int a = mlx_key_hook(param.win, display_str, (void *)&param);
// 	// int b = mlx_mouse_hook(param.win, display_str, (void *)&param);
// 	// printf("b:%d\n", b);
// 	// int a = mlx_expose_hook(param.win, print_str, (void *)&param);
// 	// printf("a:%d\n",a);
// 	mlx_loop(param.mlx);
// }

// int main()
// {
//     void *mlx;
//     void *win, *img;
// 	int width, height;

// 	width = 32;
// 	height = 32;
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "so_long");

//     img = mlx_xpm_file_to_image(mlx, "textures/env/ground.xpm", &width , &height);
//     mlx_put_image_to_window(mlx, win, img, 50, 50);
//     mlx_loop(mlx);
// }

#include <mlx.h>

#define NUM_FRAMES 7
#define FRAME_DELAY 1 // Delay between frames in microseconds

// Structure to hold information about the animation
typedef struct {
    void *mlx;
    void *win;
    void *images[NUM_FRAMES];
    char *frames[NUM_FRAMES];
    int current_frame;
    int size_win;
} Animation;

// Load XPM images
// Load XPM images
// Load XPM images
// Load XPM images
void load_images(Animation *animation) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        animation->images[i] = mlx_xpm_file_to_image(animation->mlx, 
                                                     animation->frames[i],
                                                     NULL,
                                                     NULL);
    }
}



// Update the animation frame
void update_frame(Animation *animation) {
    animation->current_frame = (animation->current_frame + 1) % NUM_FRAMES;
}

// Draw the current frame
void draw_frame(Animation *animation) {
    mlx_put_image_to_window(animation->mlx,
                            animation->win,
                            animation->images[animation->current_frame],
                            0, 0);
}

// Main animation loop
void animate(Animation *animation) {
    while (1) {
        update_frame(animation);
        draw_frame(animation);
        mlx_loop_hook(animation->mlx, mlx_do_sync, animation->mlx);
        mlx_loop(animation->mlx);
        usleep(FRAME_DELAY); // Delay between frames
    }
}


int main() {
    // Initialize MLX
    Animation animation;
    animation.frames[0] = "textures/collectible/coin0.xpm";
    animation.frames[1] = "textures/collectible/coin1.xpm";
    animation.frames[2] = "textures/collectible/coin2.xpm";
    animation.frames[3] = "textures/collectible/coin3.xpm";
    animation.frames[4] = "textures/collectible/coin4.xpm";
    animation.frames[5] = "textures/collectible/coin5.xpm";
    animation.frames[6] = "textures/collectible/coin6.xpm";
    animation.mlx = mlx_init();
    animation.win = mlx_new_window(animation.mlx, 500, 500, "Animation");
    animation.current_frame = 0;

    // Load XPM images
    load_images(&animation);

    return 0;
}
