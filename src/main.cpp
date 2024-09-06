#define SIZE_16
#define SIZE_32
#define SIZE_64
#define ALLOW_FLOAT

#include "../include/defs.h"

#define CHUNKS_H SIZED(4, 16, 64)
#define CHUNKS_V SIZED(1, 4, 16)
#define CHUNK_SIZE_H 16
#define CHUNK_SIZE_V 16
#define IMAGE_DIM 16

////////////////

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

int main() {
    
    return 0;
}