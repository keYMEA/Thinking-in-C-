#ifndef BITVECTOR_H_INCLUDED
#define BITVECTOR_H_INCLUDED

class BitVector
{
	unsigned char* bytes;
	int Bits, numBytes;
public:
	BitVector();                  //Default: 0 size
	BitVector(unsigned char* init, int size = 8);
	//init points to an array of bytes
	//size is measured in bytes
	BitVector(char* binary);      //binary is a string of 1s and 0s
	~BitVector();
	void set(int bit);
	void clear(int bit);
	int read(int bit);
	int bits();                   //number of bits in the vector
	void bits(int size);            //Set number of bits
	void print(const char* msg = "");
};

#endif // BITVECTOR_H_INCLUDED
