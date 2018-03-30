/* These are defined here, because it is unlikely they will require changing */
/* value for D, the draw plane distance */
#define MODE7_D 256
/* value for N, the near clipping pane */
#define MODE7_N +24
/* value for F, the far clipping pane */
#define MODE7_F +1024

/* Determines how sprites are anchored in m7_draw_sprite() */
#define MODE7_ANCHOR_BOTTOM 1

/* 3-dimentsional vector structure */
typedef struct vector3 {
    double x,y,z;
} Vector3;

/* Initializes the module. x,y,w,h defines the viewport
in which the mode-7 stuff will be drawn */
void m7_init(int x, int y, int w, int h);

/* Cleans up the module. */
void m7_deinit();

/* Clears the z-buffer, needs to be called on every frame */
void m7_clear_zbuf();

/* Getters and setters for the camera parameters */
void m7_set_camera_pos(double x, double y, double z);
void m7_get_camera_pos(double *x, double *y, double *z);
void m7_set_camera_ang(double phi, double theta);
void m7_get_camera_ang(double *phi, double *theta);

/* Sets the camera angle such that it looks at (x,y,z) from its current position */
void m7_lookat(double x, double y, double z);

/* Enable fog, of the specified color */
void m7_enable_fog(unsigned int color);

/* Disables fog */
void m7_disable_fog();

/* Function that will be used to draw the floor through m7_draw_floor()
 * pwx and pwz are the x and z coordinates of the pixel on the floor.
 * Data is passed unaltered through m7_draw_floor()
 */
typedef unsigned int (*m7_plotfun)(void *data, double pwx, double pwz);

/* Draws the floor using a specific plotfun. Data is passed to plotfun unaltered. */
void m7_draw_floor(Bitmap *dst, m7_plotfun plotfun, void *data);

/* Draws the bitmap `src` as a skybox on the bitmap `dst` using the current camera
 * parameters.
 * It is stretched on the x dimension to span the entire circumference of
 * the horizon. It is stretched to `height` pixels on the y dimension.
 * `background` is the color of pixels above the skybox.
 */
void m7_draw_skybox(Bitmap *dst, Bitmap *src, int height, unsigned int background);

/* Draws a sprite at position (wx, wy, wz) in the world on the bitmap dst,
 * scaled according to its distance from the camera, and taking the z-buffer
 * into account.
 * The sprite is blitted from the bitmap src in the ara defined by sx, sy, sw, sh.
 * The color of the src bitmap is used as a mask color.
 * The value of MODE7_ANCHOR_BOTTOM determines whether the sprite is anchored at the
 * bottom (useful for sprites walking on the floor) or anchored at the center
 * (useful for sprites floating in the air)
 */
void m7_draw_sprite(Bitmap *dst, double wx, double wy, double wz, Bitmap *src, int sx, int sy, int sw, int sh);

/* Draws a filled triangle with world coordinates given by the 3 vectors in `tri`.
 * It uses the color of the bitmap `bmp` (as per `bm_set_color()`).
 */
void m7_draw_tri(Bitmap *bmp, Vector3 tri[3]);

/* Finds the angle of an object facing in direction `phi_o`
 * relative to the camera.
 * It is used to choose the appropriate sprite for an object.
 */
double m7_rel_angle(double phi_o);
