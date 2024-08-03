// Clear the display
#define CLS 0x00E0

// Return from a subroutine
#define RET 0x00EE

// Jump to address NNN
#define JP_ADDR 0x1NNN

// Call subroutine at NNN
#define CALL_ADDR 0x2NNN

// Skip next instruction if Vx = nn
#define SE_VX_BYTE 0x3XNN

// Skip next instruction if Vx != nn
#define SNE_VX_BYTE 0x4XNN

// Skip next instruction if Vx = Vy
#define SE_VX_VY 0x5XY0

// Set Vx = nn
#define LD_VX_BYTE 0x6XNN
// Set Vx = Vx + nn
#define ADD_VX_BYTE 0x7XNN

// Set Vx = Vy
#define LD_VX_VY 0x8XY0

// Set Vx = Vx OR Vy
#define OR_VX_VY 0x8XY1

// Set Vx = Vx AND Vy
#define AND_VX_VY 0x8XY2

// Set Vx = Vx XOR Vy
#define XOR_VX_VY 0x8XY3

// Set Vx = Vx + Vy, set VF = carry
#define ADD_VX_VY 0x8XY4

// Set Vx = Vx - Vy, set VF = NOT borrow
#define SUB_VX_VY 0x8XY5

// Set Vx = Vx SHR 1
#define SHR_VX 0x8XY6

// Set Vx = Vy - Vx, set VF = NOT borrow
#define SUBN_VX_VY 0x8XY7

// Set Vx = Vx SHL 1
#define SHL_VX 0x8XYE

// Skip next instruction if Vx != Vy
#define SNE_VX_VY 0x9XY0

// Set I = nnn
#define LD_I_ADDR 0xANNN

// Jump to location nnn + V0
#define JP_V0_ADDR 0xBNNN

// Set Vx = random byte AND nn
#define RND_VX_BYTE 0xCXNN

// Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision
#define DRW_VX_VY_NIBBLE 0xDXYN

// Skip next instruction if key with the value of Vx is pressed
#define SKP_VX 0xEX9E

// Skip next instruction if key with the value of Vx is not pressed
#define SKNP_VX 0xEXA1

// Set Vx = delay timer value
#define LD_VX_DT 0xFX07

// Wait for a key press, store the value of the key in Vx
#define LD_VX_K 0xFX0A

// Set delay timer = Vx
#define LD_DT_VX 0xFX15

// Set sound timer = Vx
#define LD_ST_VX 0xFX18

// Set I = I + Vx
#define ADD_I_VX 0xFX1E

// Set I = location of sprite for digit Vx
#define LD_F_VX 0xFX29

// Store BCD representation of Vx in memory locations I, I+1, and I+2
#define LD_B_VX 0xFX33

// Store registers V0 through Vx in memory starting at location I
#define LD_I_VX 0xFX55

// Read registers V0 through Vx from memory starting at location I
#define LD_VX_I 0xFX65
