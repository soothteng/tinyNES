#include "cpu.h"

namespace sn {

    CPU::CPU() {
        r_a = 0;
        r_x = 0;
        status = 0;
        r_pc = 0;
    }

    CPU::~CPU() {}

    void CPU::set_zn_ng(byte result) {
        if (result == 0) {
            status = status | 0x02;
        } else {
            status = status & 0xFD;
        }

        if ((result & 0x80) != 0) {
            status = status | 0x80;
        } else {
            status = status & 0x7F;
        }
    }

    void CPU::inx() {
        r_x = r_x + 1;
        set_zn_ng(r_x);
    }

    void CPU::lda(byte value) {
        r_a = value;
        set_zn_ng(r_a);
    }

    void CPU::tax() {
        r_x = r_a;
        set_zn_ng(r_x);
    }

    void CPU::execute(std::vector<byte> &program) {
        r_pc = 0;

        while (true) {
            byte opcode = program[r_pc];
            r_pc += 1;
            switch (opcode) {
                case 0xA9: {
                    byte param = program[r_pc];
                    r_pc += 1;
                    lda(param);
                } break;
                case 0xAA: {
                    tax();
                } break;
                case 0xE8: {
                    inx();
                } break;
                case 0x00: {
                    return;
                }
            }
        }
    }

};  // namespace sn
