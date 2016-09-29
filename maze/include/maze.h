#ifndef _MAZE_H_
#define _MAZE_H_

#include <SDL2/SDL.h>
#include <math.h>

typedef struct s_instance
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} t_instance;

typedef struct s_map
{
    int *map;
    int height; /* grid units */
    int width; /* grid units */
} t_map;

typedef struct s_pov
{
    float player_x; /* grid units */
    float player_y; /* grid units */
    float player_angle; /* degrees */
    int dpp; /* distance of player to projection plane in pixels */
    float asr; /* angle b/w subsequent rays of fov in degrees */    
} t_pov;

#define WIN_WIDTH 640 /* pixel units, same as projection plane width */
#define WIN_HEIGHT 480 /* pixel units, same as projection plane height */

#define CUBE_SIZE 64 /* pixel units */

#define FOV 60.00 /* degrees */
#define PI 3.14159
#define DEGREES_TO_RADIANS(x) ((x) * PI / 180)

int init_instance(t_instance *);
void render_bg(t_instance *);
int poll_events(void);
int init_maze(t_map *, t_pov *);
void print_mem(t_map *, t_pov *);
int horz_intersect(t_map *, t_pov *);
int vert_intersect(t_map *, t_pov *);
int wall_check(t_map *, int, int);
int dist_2wall(int, int, float);
int comp_dist(int, int);
void draw_wall(int, t_pov *, t_instance *);
void kill_maze(t_instance *);

#endif