# Wolfenstein3d
The goal of cub3d is to make something using raycasting (like Wolfenstein 3D).

In this 42 project we are asked to extract information from a .cub file and use that information to draw a 3d maze on the screen using raycasting principles.

Example of a valid cub file's information:
```
R 1920 1080

NO ./textures/greystone.xpm
SO ./textures/purplestone.xpm
WE ./textures/redbrick.xpm
EA ./textures/wood.xpm

S ./textures/creeper.xpm
F 77,92,53
C 163,208,230

		1111111111111111111111111
		1000000000110000000000001
		1011000001110000002000001
		1001000000000000000002001
111111111011000001110000000000001
100000000011000001110111110111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

I believe this project has several challenges

1. Finding the right way to extract the cub information.
1. Parsing the cub correctly.
1. Using and understanding the minilibx drawing tool.
1. Understanding raycasting and the DDA algorithm.
1. Creating the bmp screenshot file.

## Cub parsing

If someone writes an invalid .cub file the program must stop, free the memory allocated up until that point and show some sort of error message.
So basically we need to imagine all the ways that things can go wrong. Not only that but we should be saving the information as we go.

A few things to test:
- Resolution values that are bigger that the screens that we have in school or non-digit numbers or more than 2 values (width and height)
- Textures are a file that doesnt exist (open function would fail) or not a xpm file.
- There are multiple textures for the same wall (north wall texture).
- RGBs dont have 3 numbers, are separated by an invalid character (not a comma) or have values below 0 or above 255.
- There are invalid characters in the cub.

On the map:
- Multiple players or no player.
- Invalid characters.
- Map not closed 

## Understanding the minilibx tool:

MLX42 is a performant, easy to use, cross-platform, minimal windowing graphics library to create graphical applications without having to work directly with the native windowing framework of the given operating system.

It provides primitive tools to draw textures onto the window as well as modifying them at runtime as they get displayed on the window.
In our case we use MLX codam.
here is the link: https://github.com/codam-coding-college/MLX42.git

Here are the main considerations and most difficult concepts explained:

We need to initiate and save the pointer to several things:
- The minilibx itself:
  - `void *mlx_ptr = mlx_init();`
- The window you will draw in:
  - `void    *win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Name of the window");`


And now the minilibx gives you 2 options to draw on the screen:
- You can either use the mlx_put_pixel for every pixel you want to change,
or
- You can create an image, change all the pixel colors you want and use the mlx_put_image_to_window a single time.

So, in terms of time and resource efficiency we can agree that using images, especially for a big screen would be preferable, right?

I'm going to assume that you agree with me so that I only need to explain images and not pixels.


### Images

First you must create an image:

All the images to be created will need these variables so you might as well create a struct to hold them

```
typedef struct		s_img
{
	void		*ptr;
	char		*addr;		// In my code I changed this to int *, which I will explain in a second
	int		bitsinpixel;	//when using ARGB this value is always 32
	int		line_bytes;	//This value represents (your image width) * 4 which I will also explain after
	int		endian;		//This value can be either 0 or 1 and will indicate how the ARGB bytes are organized (from front to back or back to front)
}			t_img;
```

```
img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (ft_error("Failed to create image\n"), 1);
```
this is a link explain MLX in detail: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

## Raycasting Part and Drawing calculations

Okay so for the raycasting part the main resources that I followed were the following:

To create a minimap and use trigonometrics for raycasting:
- [Pikuma Javascript Raycasting Introduction](https://courses.pikuma.com/courses/take/raycasting/lessons/7485598-introduction-and-learning-outcomes)
(Before the course was free)

To understand the calculations behind the projection itself:
- [Permadi's Raycasting Tutorial](https://www.permadi.com/tutorial/raycast/rayc1.html)

For a fun Youtube video implementing Raycasting in C:
- I watched [this video](https://www.youtube.com/watch?v=gYRrGTC7GtA)



I will try to simplify it as much as possible:

Raycasting is basically taking your field of view, dividing it by your window width and calculating the distance from your face to the wall strip in each one of these divisions. (Explanations are clearer in Pikuma's Javascript tutorial).

### Drawing calculations

Let's picture this:
- Our window is 500 pixels width and 500 pixels height.
- We pick a [field of view](https://en.wikipedia.org/wiki/Field_of_view) of 60 degrees (usual in FPS games). The bigger your field of view the more you can see around you and the closest you get to a 360 picture. With a field of view of 60 you just see what's in front of you.
- Our height is 1,5meters.
- The wall's height is 3 meters.
- The wall is 6 meters away from us.

Okay, now I will help you calculate the size that the walls will have on the screen (a simplified version to be better understood).

In order to calculate them I will use the concept of triangle similarity and the [Projection Plane](https://www.permadi.com/tutorial/raycast/rayc9.html):

This concept is in my opinion the most important to grasp in order to draw not only the walls but also the sprites, floor and ceiling.
Using our screen and field of view we have 2 similar triangles.

> One triangle is between our face and the projection plane (the screen) and we can [calculate](https://www.permadi.com/tutorial/raycast/rayc5.html) this distance.
Half the screen size / tan(half our field of view)
(500/2) / tan(30 degrees) = 433.012701892
Our face is 433.012701892 pixels away from the screen. 

I know.. I know... pixels is not really a measurement of distance outside the screen, but it doesnt matter. What matters is this distance in pixels from our face to the projection plane/screen is proportional to the distance in meters from our face to the wall (6 meters).

> The other triangle is between our face and the wall (which we know is 6 meters away).

Okay now look at [this](https://www.permadi.com/tutorial/raycast/rayc9.html).

Projected wall height = wall actual height / distance to the wall * distance to projection plane

Projected wall height = (3 meters / 6 meters) * 433.012701892 = 216.506350946 ≈ 216 pixels.

GREAT!! We now know the height in pixels that our wall will have on our screen! Yay.

Now were do we place this line?

As we said in the beggining our player is 1,5 meters tall.
(1.5/3) * 500 = 250 we will draw (3-1.5)/3 = 0.5 = the middle of our wall. (Don't worry about these calculations. In the Wolfenstein game the player was half of the walls so the middle of the screen will always correspond with the middle of the wall/sprites.

So the wall line has to be centered on the screen.
The beggining of the wall strip will be on 250 - (216/2) = 142nd pixel
The end of the wall strip will be on the 250 + (216/2) = 358th pixel

We draw a line from the 142nd pixel to the 358th and booom. We have a wall strip.

Now we just have to repeat this process for each collumn/width pixel on our screen. To do this we use the raycasting principle.

### Raycasting

Okay for this part I really suggest following [Pikuma's Tutorial](https://courses.pikuma.com/courses/take/raycasting/lessons/7485598-introduction-and-learning-outcomes).

The main challenge was converting the Javascript code into C. Here are the main things to consider:
- Instead of classes for variables just create structs, create the same functions.
- Using double data type for calculations (If you use integer you will lose all decimal point information). Also, <math.h> functions take double as parameters.
- Converting double to int to change the values of the actual coordinates of the pixels (there is no 2.4123, 3.124124 coordinate).
- To avoid overflows do a simple protection like this:

```
if (x < 0)
	x = 0;
if (y < 0)
	y = 0;
if (x >= img_width)
	x = img_width - 1.0;
if (y >= img_width)
	x = img_width - 1.0;
```

This will grant that if when converting to integer if the values are not valid (below zero or above the maximum width) it will fix them and put the first and last value respectively, when needed. 

After you finish the tutorial you will understand how to use the player rotation in radians, you will have a cute minimap, and the distances for each one of the rays. You will then use these distances to draw lines the way I just described.

### Wall textures

Okay once we followed Pikuma's tutorial these are the things we still have left to do:

1. Draw the walls using the distances of the rays (don't forget to correct the [fisheye effect](https://permadi.com/1996/05/ray-casting-tutorial-8/)
2. Assign each texture to the correct wall.
3. Find out which part of the wall we are hitting so we know the correct part of the texture to assign to that wall strip.

To find the correct wall using the ray angle and the wall orientation (Horizontal or Vertical).

For example if the ray rotation angle is 0 radians (looking to the right) and we hit a vertical wall we know that the texture we will choose is the East side texture.

To find which part of the wall we are hitting I suggest looking at [Permadi's](https://www.permadi.com/tutorial/raycast/rayc10.html) explanation.

But summing up.
We define how wide we want the walls to be:

Following the previous example in which the walls were 3 meters, maybe we want the walls width to be 3 meters as well so that the three dimensional space is divided in squares/cubes and to make it easier to imagine.

Imagine this map:
```
Imagine this map:
  _
11111
10001
10001
10N01
11111
```
It is definitely easier to imagine if each represents a 3 meters square, right? What is great about Pikuma's tutorial is that we can use the tile_size to visualize this and just use the distance in pixels on the map as the way to do the raycasting.

So in this case our player would be:
In 2.5 * 3 = 7.5 x position ('1' & '0' full squares and half the 'N' square)
In 3.5 * 3 = 10.5 y position ('1' & '0' & '0' full squares and half the 'N' square)

Okay, hopefully this makes sense because with this scale we can now calculate the corresponding texture strip.

Imagine our ray hits a wall in the (7.5, 3) position (in the middle of third wall (I put an underscore above it to show which wall I'm talking about)).

We can do a while loop

```
while (x >= 3)
	x-=3
```
We will end up with 1.5. This represent half the square size on our map.

To find the corresponding slice on the texture we can calculate this through:
1.5/3 * texture_width.

If a texture is 64 pixels. the wall strip's texture will be drawn with the 32nd texture strip (x = 32).