#define CHUNKS_H 4
#define CHUNKS_V 1
#define CHUNK_SIZE_H 16
#define CHUNK_SIZE_V 16

typedef struct World {
  Chunk chunks[CHUNKS_H][CHUNKS_V][CHUNKS_H];
} World;

typedef struct Chunk {
  BlockState blocks[CHUNK_SIZE_H][CHUNK_SIZE_V][CHUNK_SIZE_H];
} Chunk;

typedef struct BlockPos {
  int x;
  int y;
  int z;
} BlockPos;

typedef struct identifier {
  string name;
  string path;
} Identifier;

typedef struct Block {
  Identifier* id;
} Block;
typedef struct BlockState {
  Block block;
}

typedef struct Player {
  
}
