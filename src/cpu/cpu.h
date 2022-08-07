#ifndef CPU_H
#define CPU_H

#include <assert.h>
#include <stdint.h>

#include <vector>

namespace sn {
    using byte = uint8_t;
    using address = uint16_t;

    class CPU {
       public:
        CPU();
        ~CPU();
        void execute(std::vector<byte> &program);

        // registers
        address r_pc;
        byte r_a;
        byte r_x;

        // status flags
        byte status;

       private:
        // other funcs
        void set_zn_ng(byte res);
        // opcode funcs
        void inx();
        void lda(byte value);
        void tax();
    };
};  // namespace sn

#endif  // !CPU_H
