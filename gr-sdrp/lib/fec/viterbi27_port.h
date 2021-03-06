#ifndef VITERBI27_PORT_H
#define VITERBI27_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "fec.h"

#define	V27POLYA	0x6d
#define	V27POLYB	0x4f

void *create_viterbi27_port(int len);
void set_viterbi27_polynomial_port(int polys[2]);
int init_viterbi27_port(void *p,int starting_state);
int chainback_viterbi27_port(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
void delete_viterbi27_port(void *p);
int update_viterbi27_blk_port(void *p,unsigned char *syms,int nbits);
void encode_viterbi27_port(unsigned char *bits, int nbits, unsigned char *return_bits);

#ifdef __cplusplus
}
#endif

#endif
