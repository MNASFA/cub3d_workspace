#Cub3D

A 3D maze exploration game inspired by Wolfenstein 3D, built using raycasting techniques with the miniLibX graphics library.

📋 Table of Contents

🎮 About
cub3D is a first-person 3D maze exploration game that recreates the raycasting engine made famous by Wolfenstein 3D. This project demonstrates fundamental 3D rendering techniques, game loop implementation, and real-time user interaction.
The project is part of the 42 School curriculum and focuses on:

Understanding raycasting algorithms
Working with graphics libraries
Managing textures and colors
Implementing smooth player movement and rotation
Parsing and validating configuration files

✨ Features
Mandatory Features

✅ First-person 3D view using raycasting
✅ Textured walls with different textures for each direction (N, S, E, W)
✅ Customizable floor and ceiling colors
✅ Smooth player movement (W, A, S, D keys)
✅ Camera rotation (Left/Right arrow keys)
✅ Minimap display in corner
✅ Map parsing from .cub configuration files
✅ Comprehensive error handling and validation

Bonus Features

🎯 Wall collision detection
🗺️ Minimap system with real-time player position
🔫 Animated weapon with shooting mechanics
☀️ Animated sun/sky element
🖱️ Mouse-controlled camera rotation
🎨 Enhanced visual effects

📁 Project Structure
cub3D/
├── animation/              # Weapon and sun animation frames (XPM files)
│   ├── 0.xpm - 14.xpm     # Weapon animation frames
│   └── s1.xpm - s45.xpm   # Sun animation frames
├── textures/              # Wall texture files
│   ├── north_wall.xpm
│   ├── south_wall.xpm
│   ├── east_wall.xpm
│   └── west_wall.xpm
├── maps/                  # Example map configurations
│   ├── map.cub
│   └── test.cub
├── src/                   # Source files
│   ├── main.c
│   ├── init.c
│   ├── init_dir.c
│   ├── parsing/           # Map and config parsing
│   │   ├── parse_file.c
│   │   ├── parse_map.c
│   │   ├── parse_textures.c
│   │   ├── parse_colors.c
│   │   ├── validation.c
│   │   ├── validation_2.c
│   │   ├── map_line.c
│   │   ├── parsing_utils.c
│   │   └── read_all_lines.c
│   └── rendring/          # Rendering and game loop
│       ├── init_mlx.c
│       ├── render_map.c
│       ├── render_minimap.c
│       ├── hooks.c
│       └── hooks_utils.c
├── raycasting/            # Raycasting engine
│   ├── raycasting.h
│   ├── raycasting.c
│   ├── dda.c
│   ├── wall_dimension.c
│   ├── draw_texture.c
│   ├── draw_sun.c
│   ├── draw_weapon.c
│   ├── sun.c
│   └── weapon.c
├── get_next_line/         # GNL utility for file reading
│   ├── get_next_line.c
│   └── get_next_line_utils.c
├── minilibx/              # Graphics library
├── cub3d.h               # Main header file
├── Makefile              # Build configuration
├── spliiit.c             # String splitting utility
├── utils.c               # Utility functions
├── utils_1.c
└── utils_2.c

🔧 Installation
Prerequisites

GCC compiler
Make
X11 development libraries (Linux)
XQuartz (macOS)

Linux Installation
bash# Install dependencies
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Clone the repository
git clone https://github.com/yourusername/cub3D.git
cd cub3D

# Compile the project
make

# Run the game
./cub3D maps/test.cub
macOS Installation
bash# Install XQuartz
brew install xquartz

# Reboot your system
reboot

# Clone and compile
git clone https://github.com/yourusername/cub3D.git
cd cub3D
make

# Run the game
./cub3D maps/test.cub
🎯 Usage
bash./cub3D <map_file.cub>
Example:
bash./cub3D maps/test.cub
```

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `Mouse` | Rotate camera (bonus) |
| `Space` | Shoot weapon (bonus) |
| `ESC` | Exit game |

## 🗺️ Map Format

The game uses `.cub` configuration files with the following format:
```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110000011111111
11110111111111011100000010001
11110111100010001101010010001
11000000000100000000000010001
10000000000000001100000000001
100000000000W0001101010000001
11000001110101011111011110001
11110111 1110101 101111010001
11111111 1111111 111111111111

Configuration Elements

NO, SO, WE, EA: Paths to wall textures
F: Floor color in RGB format (R,G,B)
C: Ceiling color in RGB format (R,G,B)

Map Characters
CharacterMeaning0Empty space (walkable)1WallNPlayer start position (facing North)SPlayer start position (facing South)EPlayer start position (facing East)WPlayer start position (facing West) Void (space)
Map Rules

Map must be surrounded by walls (1)
Must contain exactly one player start position
Spaces in the map are handled as void
Map must be rectangular and properly enclosed

🔬 Technical Details
Raycasting Algorithm
The project implements the DDA (Digital Differential Analysis) algorithm for raycasting:

Ray Calculation: For each vertical screen column, cast a ray from the player position
DDA Algorithm: Step through the grid until hitting a wall
Wall Distance: Calculate perpendicular distance to avoid fisheye effect
Wall Height: Determine wall slice height based on distance
Texture Mapping: Map appropriate texture to the wall slice

Key Components

Player Structure: Stores position, direction, and camera plane vectors
Ray Structure: Contains ray direction for each screen column
DDA Structure: Manages grid traversal and hit detection
Texture System: Loads and maps XPM textures to walls
Minimap Rendering: Real-time scaled map view with player position

Performance Optimizations

Efficient DDA stepping algorithm
Optimized texture mapping
Minimal redundant calculations
Frame buffering for smooth rendering

📸 Screenshots
Add your game screenshots here
🎁 Bonus Features
Implemented Bonuses

Wall Collision System: Prevents player from walking through walls with buffer zone
Minimap: Real-time corner minimap showing player position and surroundings
Animated Weapon: 15-frame weapon animation triggered by spacebar
Animated Sun: 45-frame sun animation in the sky
Mouse Controls: Smooth camera rotation using mouse movement

Bonus Technical Details

Animation System: Frame-based animation with configurable frame rates
Collision Detection: Multi-point collision checking with corner detection
Mouse Sensitivity: Adjustable rotation speed via SENSITIVITY constant
Alpha Blending: Transparent pixel handling for weapon and sun sprites

👥 Authors

hmnasfa - Main developer
aboukhmi - Raycasting engine implementation

🙏 Acknowledgments

42 School for the project specification
John Carmack and John Romero for Wolfenstein 3D inspiration
Lode Vandevenne for raycasting tutorials
miniLibX developers

📝 License
This project is part of the 42 School curriculum and follows the school's policies.
🐛 Known Issues

None currently reported

🚀 Future Improvements

Sprite rendering for enemies/objects
Multiple floor levels
Textured floors and ceilings
Sound effects and music
More complex map features (doors, secrets)


Note: This project was created as part of the 42 School curriculum and demonstrates understanding of 3D graphics programming, raycasting, and game development fundamentals.
