/*
    Copyright 2017 Zheyong Fan, Ville Vierimaa, and Ari Harju

    This file is part of GPUQT.

    GPUQT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GPUQT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GPUQT.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "common.h"
class Vector;
class Model;

class Hamiltonian
{
public:
  Hamiltonian(Model&);
  ~Hamiltonian();

  void apply(Vector&, Vector&);
  void apply_commutator(Vector&, Vector&);
  void apply_current(Vector&, Vector&);
  void kernel_polynomial(Vector&, Vector&, Vector&);
  void chebyshev_01(Vector&, Vector&, Vector&, real, real, int);
  void chebyshev_2(Vector&, Vector&, Vector&, Vector&, real, int);
  void chebyshev_1x(Vector&, Vector&, real);
  void chebyshev_2x(Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, real, int);

private:
  void initialize_gpu(Model&);
  void initialize_cpu(Model&);

  int* neighbor_number;
  int* neighbor_list;
  real* potential;
  real* hopping_real;
  real* hopping_imag;
  real* xx;
  int grid_size;
  int n;
  int max_neighbor;
  real energy_max;
};
