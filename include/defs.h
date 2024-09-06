#include <stdio.h>

#define DECLARE(k, i) k i; typedef k i i;
#ifdef ALLOW_FLOAT
    #define FLOATING(y, n) y
#else
    #define FLOATING(y, n) n
#endif
#ifdef SIZE_64
    #define SIZED(S16, S32, S64) S64
#else
    #ifdef SIZE_32
        #define SIZED(S16, S32, S64) S32
    #else
        #define SIZED(S16, S32, S64) S16
    #endif
#endif
#define ARG(...) __VA_ARGS__

typedef char* string;
typedef short int_m16;
typedef unsigned short uint_m16;
typedef SIZED(short, int, int) int_m32;
typedef unsigned SIZED(short, int, int) uint_m32;
typedef SIZED(short, int, long) int_m64;
typedef unsigned SIZED(short, int, long) uint_m64;

typedef struct Identifier {
    string name;
    string path;
} Identifier;

typedef struct Texture {
    int rgb[IMAGE_DIM][IMAGE_DIM];
} Texture;

typedef enum Direction {
    UP,
    DOWN,
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

typedef struct Block {
    Identifier* id;
    Texture* up;
    Texture* down;
    Texture* north;
    Texture* east;
    Texture* south;
    Texture* west;
} Block;
typedef struct BlockState {
    Block block;
} BlockState;

typedef struct Chunk {
    BlockState blocks[CHUNK_SIZE_H][CHUNK_SIZE_V][CHUNK_SIZE_H];
} Chunk;

typedef struct World {
    Chunk chunks[CHUNKS_H][CHUNKS_V][CHUNKS_H];
} World;

typedef struct BlockPos {
    int_m32 x;
    int_m32 y;
    int_m32 z;
} BlockPos;

typedef struct Position {
    float x;
    float y;
    float z;
} Position;

typedef struct Player {
    Identifier* id;
    Position pos;
    float yaw;
    float pitch;
} Player;

// Identifier

// Texture

// Direction

// Block
Identifier getId(Block block);
Texture getTexture(Block block, Direction dir);
int getHardness(Block block);

// BlockState
Block getBlock(BlockState state);

// Chunk
BlockState getBlockAt(Chunk chunk, BlockPos pos);
Chunk getChunkInDir(Chunk chunk, Direction dir);
int_m16 getSizeX(Chunk chunk);
int_m16 getSizeY(Chunk chunk);
int_m16 getSizeZ(Chunk chunk);
int_m32 getSize(Chunk chunk);

// World
BlockState getBlockAt(World world, BlockPos pos);
Chunk getChunkAt(World world, BlockPos pos);
int_m32 getSizeX(World world);
int_m32 getSizeY(World world);
int_m32 getSizeZ(World world);
int_m64 getSize(World world);

// BlockPos

// Position

// Player