#ifndef BITCOIN_CHAINPARAMSSEEDS_H
#define BITCOIN_CHAINPARAMSSEEDS_H
/**
 * List of fixed seed nodes for the bgcoin network
 * AUTOGENERATED by contrib/seeds/generate-seeds.py
 *
 * Each line contains a BIP155 serialized (networkID, addr, port) tuple.
 */
static const uint8_t chainparams_seed_main[] = {
    0x01,0x04,0x26,0xf2,0xc8,0xd9,0x2e,0x59,
    0x01,0x04,0xb9,0xf9,0xe1,0xc6,0x2e,0x59,
    0x01,0x04,0x33,0x59,0xac,0x61,0x00,0x00,
    0x01,0x04,0x33,0x59,0xac,0x4c,0x00,0x00,
    0x01,0x04,0xb9,0xfa,0xf0,0x51,0x00,0x00,
    0x01,0x04,0x8e,0xab,0x14,0xc0,0x00,0x00,
    0x01,0x04,0xb9,0xb7,0x23,0x5b,0x00,0x00,
    0x01,0x04,0x59,0x98,0xab,0x6f,0x00,0x00,
};

static const uint8_t chainparams_seed_test[] = {
    0x01,0x04,0x26,0xf2,0xc8,0xd9,0x55,0x69,
    0x01,0x04,0xb9,0xf9,0xe1,0xc6,0x55,0x69,
    0x01,0x04,0x9c,0x43,0x53,0x62,0x55,0x69,
};

static const uint8_t chainparams_seed_testnet4[] = {
    0x01,0x04,0x26,0xf2,0xc8,0xd9,0x7c,0x79,
    0x01,0x04,0xb9,0xf9,0xe1,0xc6,0x7c,0x79,
    0x01,0x04,0x9c,0x43,0x53,0x62,0x7c,0x79,
};
#endif // BITCOIN_CHAINPARAMSSEEDS_H
