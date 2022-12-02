#define NOP 0b00000000
////////////////////////////////


/*read and write memory operations*/
#define WRM 0b11100000 //write main memory
#define WMP 0b11100001 //write ram port
#define WRR 0b11100010 //write rom port

#define RDM 0b11101001 //read main memory
#define RDR 0b11101010 //read rom port

/*read and write status operations*/
#define WR0 0b11100100 //write status char 0
#define WR1 0b11100101 //write status char 1
#define WR2 0b11100110 //write status char 2
#define WR3 0b11100111 //write status char 3

#define RD0 0b11101100 //read status char 0
#define RD1 0b11101101 //read status char 1
#define RD2 0b11101110 //read status char 2
#define RD3 0b11101111 //read status char 3

/*rotate operations*/
#define RAL 0b11110101 //rotate left
#define RAR 0b11110110 //rotate right

/*main memory operations*/
#define ADM 0b11101011 //add main memory
#define SBM 0b11101000 //subtract main memory

/*accumulator operations*/
#define IAC 0b11110010 //increment accumulator
#define DAC 0b11111000 //decrement accumulator

/*clear operations*/
#define CLB 0b11110000 //clear both
#define CLC 0b11110001 //clear carry

/*carry operations*/
#define CMC 0b11110011 //complement carry
#define CMA 0b11110100 //complement

#define TCC 0b11110111 //transfer carry and clear
#define TCS 0b11111001 //transfer carry subtract
#define STC 0b11111010 //set carry

/*other operations*/
#define DAA 0b11111011 //decimal adjust accumulator
#define KBP 0b11111100 //keyboard process
#define DCL 0b11111101 //designate command line
