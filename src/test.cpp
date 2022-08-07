#include <assert.h>

#include <iostream>
#include <vector>

#include "cpu/cpu.h"

using namespace sn;

using byte = uint8_t;

void test_0xa9_lda_immediate_load_data() {
    std::vector<byte> vec = {0xA9, 0x05, 0x00};
    CPU cpu;
    cpu.execute(vec);
    assert(cpu.r_a == 0x05);
    assert((cpu.status & 0x02) == 0);
    assert((cpu.status & 0x80) == 0);
}

void test_0xa9_lda_zero_flag() {
    std::vector<byte> vec = {0xA9, 0x00, 0x00};
    CPU cpu;
    cpu.execute(vec);
    assert((cpu.status & 0x02) == 0x02);
}

void test_0xa9_lda_negative_flag() {
    std::vector<byte> vec = {0xA9, 0xff, 0x00};
    CPU cpu;
    cpu.execute(vec);
    assert((cpu.status & 0x80) == 0x80);
}

void test_0xaa_tax_move_a_to_x() {
    std::vector<byte> vec = {0xAA, 0x00};
    CPU cpu;
    cpu.r_a = 10;
    cpu.execute(vec);
    assert(cpu.r_x == 10);
}

void test_5_ops_working_together() {
    std::vector<byte> vec = {0xA9, 0xc0, 0xAA, 0xE8, 0x00};
    CPU cpu;
    cpu.execute(vec);
    assert(cpu.r_x == 0xC1);
}

void test_inx_overflow() {
    std::vector<byte> vec = {0xE8, 0xE8, 0x00};
    CPU cpu;
    cpu.r_x = 0xFF;
    cpu.execute(vec);
    assert(cpu.r_x == 0x01);
}

int main(int argc, char** argv) {
    test_0xa9_lda_immediate_load_data();
    test_0xa9_lda_zero_flag();
    test_0xa9_lda_negative_flag();
    test_0xaa_tax_move_a_to_x();
    test_5_ops_working_together();
    test_inx_overflow();
    std::cout << "PASS" << std::endl;
    return 0;
}
