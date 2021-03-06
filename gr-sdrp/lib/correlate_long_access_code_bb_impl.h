/* -*- c++ -*- */
/*
 * Copyright 2005,2006,2011,2012 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_SDRP_CORRELATE_LONG_ACCESS_CODE_BB_IMPL_H
#define INCLUDED_SDRP_CORRELATE_LONG_ACCESS_CODE_BB_IMPL_H

#include <sdrp/correlate_long_access_code_bb.h>

namespace gr {
  namespace sdrp {

    class correlate_long_access_code_bb_impl :
      public correlate_long_access_code_bb
    {
    private:
      unsigned long long *d_access_code;	// access code to locate start of packet
                                        //   access code is left justified in the word
      unsigned long long *d_data_reg;	// used to look for access_code
      unsigned long long *d_mask;	// masks access_code bits (top N bits are set where
                                        //   N is the number of bits in the access code)
      unsigned int d_threshold; 	// how many bits may be wrong in sync vector
      unsigned int d_len_64;

    public:
      correlate_long_access_code_bb_impl(const std::string &access_code,
				    int threshold);
      ~correlate_long_access_code_bb_impl();

      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);

      bool set_access_code(const std::string &access_code);
      void set_threshold(unsigned int new_threshold);
    };

  } /* namespace digital */
} /* namespace gr */

#endif /* INCLUDED_DIGITAL_CORRELATE_ACCESS_CODE_BB_IMPL_H */
