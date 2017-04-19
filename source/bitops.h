#ifndef BITOPS_H
#define BITOPS_H

#include <cstdint>
#include <vector>

namespace bitops {
template <class T>
constexpr T RBITS(T val, int n) {
	return val & (0xFF >> (8 - n));
}

template <class T>
constexpr T LBITS(T val, int n) {
	return val >> (8 - n);
}

template <class T>
constexpr int BITN(T val, int n) {
	return (val >> n) & 0x1;
}
}

/* -----------------------------------------------
	class to read arrays bitwise
	----------------------------------------------- */
class BitReader {
public:
	BitReader(const std::vector<std::uint8_t>& bits);
	~BitReader();
	unsigned int read(int nbits);
	std::uint8_t read_bit();
	std::uint8_t unpad(std::uint8_t fillbit);
	bool eof() const;
	bool overread() const;

private:
	static constexpr std::uint8_t MBITS(std::uint8_t val, int l, int r) {
		return bitops::RBITS(val, l) >> r;
	}

	const std::vector<std::uint8_t> data;
	std::vector<std::uint8_t>::const_iterator cbyte; // The position in the data of the byte being read.
	int cbit = 8; // The position of the next bit in the current byte.
	bool overread_ = false; // Tried to read more bits than available in the reader.
	bool eof_ = false; // Read all the bits in the reader.
};


/* -----------------------------------------------
	class to write arrays bitwise
	----------------------------------------------- */
class BitWriter {
public:
	BitWriter(int size);
	~BitWriter();
	void write(unsigned int val, int nbits);
	void write_bit(std::uint8_t bit);
	void set_fillbit(std::uint8_t fillbit);
	void pad();
	std::vector<std::uint8_t> get_data();
	int getpos() const;

private:
	static constexpr std::uint32_t RBITS32(std::uint32_t val, int n) {
		return val & (0xFFFFFFFF >> (32 - n));
	}

	static constexpr std::uint32_t MBITS32(std::uint32_t val, int l, int r) {
		return RBITS32(val, l) >> r;
	}

	std::uint8_t fillbit_ = 1;
	std::vector<std::uint8_t> data;
	int cbyte = 0; // The position in the data of the byte being written.
	int cbit = 8; // The position of the next bit in the current byte.
};

#endif