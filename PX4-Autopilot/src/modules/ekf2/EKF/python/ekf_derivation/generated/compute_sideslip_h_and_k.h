// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_sideslip_h_and_k
 *
 * Args:
 *     state: Matrix25_1
 *     P: Matrix24_24
 *     innov_var: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     H: Matrix24_1
 *     K: Matrix24_1
 */
template <typename Scalar>
void ComputeSideslipHAndK(const matrix::Matrix<Scalar, 25, 1>& state,
                          const matrix::Matrix<Scalar, 24, 24>& P, const Scalar innov_var,
                          const Scalar epsilon, matrix::Matrix<Scalar, 24, 1>* const H = nullptr,
                          matrix::Matrix<Scalar, 24, 1>* const K = nullptr) {
  // Total ops: 518

  // Input arrays

  // Intermediate terms (50)
  const Scalar _tmp0 = -state(22, 0) + state(4, 0);
  const Scalar _tmp1 = 2 * _tmp0;
  const Scalar _tmp2 = 2 * state(3, 0);
  const Scalar _tmp3 = _tmp2 * state(6, 0);
  const Scalar _tmp4 = 1 - 2 * std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp5 = _tmp4 - 2 * std::pow(state(2, 0), Scalar(2));
  const Scalar _tmp6 = _tmp2 * state(0, 0);
  const Scalar _tmp7 = 2 * state(1, 0);
  const Scalar _tmp8 = _tmp7 * state(2, 0);
  const Scalar _tmp9 = _tmp6 + _tmp8;
  const Scalar _tmp10 = -state(23, 0) + state(5, 0);
  const Scalar _tmp11 = 2 * state(2, 0);
  const Scalar _tmp12 = -_tmp11 * state(0, 0) + _tmp2 * state(1, 0);
  const Scalar _tmp13 = _tmp0 * _tmp5 + _tmp10 * _tmp9 + _tmp12 * state(6, 0);
  const Scalar _tmp14 = _tmp13 + epsilon * ((((_tmp13) > 0) - ((_tmp13) < 0)) + Scalar(0.5));
  const Scalar _tmp15 = Scalar(1.0) / (_tmp14);
  const Scalar _tmp16 = 2 * _tmp10;
  const Scalar _tmp17 = 2 * state(0, 0) * state(6, 0);
  const Scalar _tmp18 = std::pow(_tmp14, Scalar(2));
  const Scalar _tmp19 = _tmp4 - 2 * std::pow(state(1, 0), Scalar(2));
  const Scalar _tmp20 = -_tmp6 + _tmp8;
  const Scalar _tmp21 = _tmp2 * state(2, 0) + _tmp7 * state(0, 0);
  const Scalar _tmp22 = _tmp0 * _tmp20 + _tmp10 * _tmp19 + _tmp21 * state(6, 0);
  const Scalar _tmp23 = _tmp22 / _tmp18;
  const Scalar _tmp24 = _tmp15 * (_tmp1 * state(1, 0) + _tmp3) -
                        _tmp23 * (-4 * _tmp0 * state(2, 0) + _tmp16 * state(1, 0) - _tmp17);
  const Scalar _tmp25 = _tmp18 / (_tmp18 + std::pow(_tmp22, Scalar(2)));
  const Scalar _tmp26 = (Scalar(1) / Scalar(2)) * _tmp25;
  const Scalar _tmp27 = _tmp26 * state(3, 0);
  const Scalar _tmp28 = _tmp7 * state(6, 0);
  const Scalar _tmp29 = _tmp11 * state(6, 0);
  const Scalar _tmp30 =
      _tmp15 * (-_tmp1 * state(3, 0) + _tmp28) - _tmp23 * (_tmp16 * state(3, 0) - _tmp29);
  const Scalar _tmp31 = _tmp26 * state(1, 0);
  const Scalar _tmp32 = _tmp15 * (_tmp1 * state(2, 0) - 4 * _tmp10 * state(1, 0) + _tmp17) -
                        _tmp23 * (_tmp16 * state(2, 0) + _tmp3);
  const Scalar _tmp33 = _tmp26 * state(0, 0);
  const Scalar _tmp34 = 4 * state(3, 0);
  const Scalar _tmp35 = _tmp15 * (-_tmp1 * state(0, 0) - _tmp10 * _tmp34 + _tmp29) -
                        _tmp23 * (-_tmp0 * _tmp34 + _tmp16 * state(0, 0) + _tmp28);
  const Scalar _tmp36 = _tmp26 * state(2, 0);
  const Scalar _tmp37 = -_tmp24 * _tmp27 - _tmp30 * _tmp31 + _tmp32 * _tmp33 + _tmp35 * _tmp36;
  const Scalar _tmp38 = _tmp24 * _tmp33 + _tmp27 * _tmp32 - _tmp30 * _tmp36 - _tmp31 * _tmp35;
  const Scalar _tmp39 = _tmp24 * _tmp31 - _tmp27 * _tmp30 - _tmp32 * _tmp36 + _tmp33 * _tmp35;
  const Scalar _tmp40 = _tmp23 * _tmp5;
  const Scalar _tmp41 = _tmp15 * _tmp20;
  const Scalar _tmp42 = _tmp25 * (-_tmp40 + _tmp41);
  const Scalar _tmp43 = _tmp15 * _tmp19;
  const Scalar _tmp44 = _tmp23 * _tmp9;
  const Scalar _tmp45 = _tmp25 * (_tmp43 - _tmp44);
  const Scalar _tmp46 = _tmp25 * (-_tmp12 * _tmp23 + _tmp15 * _tmp21);
  const Scalar _tmp47 = _tmp25 * (_tmp40 - _tmp41);
  const Scalar _tmp48 = _tmp25 * (-_tmp43 + _tmp44);
  const Scalar _tmp49 = Scalar(1.0) / (math::max<Scalar>(epsilon, innov_var));

  // Output terms (2)
  if (H != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _h = (*H);

    _h.setZero();

    _h(0, 0) = _tmp37;
    _h(1, 0) = _tmp38;
    _h(2, 0) = _tmp39;
    _h(3, 0) = _tmp42;
    _h(4, 0) = _tmp45;
    _h(5, 0) = _tmp46;
    _h(21, 0) = _tmp47;
    _h(22, 0) = _tmp48;
  }

  if (K != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _k = (*K);

    _k(0, 0) =
        _tmp49 * (P(0, 0) * _tmp37 + P(0, 1) * _tmp38 + P(0, 2) * _tmp39 + P(0, 21) * _tmp47 +
                  P(0, 22) * _tmp48 + P(0, 3) * _tmp42 + P(0, 4) * _tmp45 + P(0, 5) * _tmp46);
    _k(1, 0) =
        _tmp49 * (P(1, 0) * _tmp37 + P(1, 1) * _tmp38 + P(1, 2) * _tmp39 + P(1, 21) * _tmp47 +
                  P(1, 22) * _tmp48 + P(1, 3) * _tmp42 + P(1, 4) * _tmp45 + P(1, 5) * _tmp46);
    _k(2, 0) =
        _tmp49 * (P(2, 0) * _tmp37 + P(2, 1) * _tmp38 + P(2, 2) * _tmp39 + P(2, 21) * _tmp47 +
                  P(2, 22) * _tmp48 + P(2, 3) * _tmp42 + P(2, 4) * _tmp45 + P(2, 5) * _tmp46);
    _k(3, 0) =
        _tmp49 * (P(3, 0) * _tmp37 + P(3, 1) * _tmp38 + P(3, 2) * _tmp39 + P(3, 21) * _tmp47 +
                  P(3, 22) * _tmp48 + P(3, 3) * _tmp42 + P(3, 4) * _tmp45 + P(3, 5) * _tmp46);
    _k(4, 0) =
        _tmp49 * (P(4, 0) * _tmp37 + P(4, 1) * _tmp38 + P(4, 2) * _tmp39 + P(4, 21) * _tmp47 +
                  P(4, 22) * _tmp48 + P(4, 3) * _tmp42 + P(4, 4) * _tmp45 + P(4, 5) * _tmp46);
    _k(5, 0) =
        _tmp49 * (P(5, 0) * _tmp37 + P(5, 1) * _tmp38 + P(5, 2) * _tmp39 + P(5, 21) * _tmp47 +
                  P(5, 22) * _tmp48 + P(5, 3) * _tmp42 + P(5, 4) * _tmp45 + P(5, 5) * _tmp46);
    _k(6, 0) =
        _tmp49 * (P(6, 0) * _tmp37 + P(6, 1) * _tmp38 + P(6, 2) * _tmp39 + P(6, 21) * _tmp47 +
                  P(6, 22) * _tmp48 + P(6, 3) * _tmp42 + P(6, 4) * _tmp45 + P(6, 5) * _tmp46);
    _k(7, 0) =
        _tmp49 * (P(7, 0) * _tmp37 + P(7, 1) * _tmp38 + P(7, 2) * _tmp39 + P(7, 21) * _tmp47 +
                  P(7, 22) * _tmp48 + P(7, 3) * _tmp42 + P(7, 4) * _tmp45 + P(7, 5) * _tmp46);
    _k(8, 0) =
        _tmp49 * (P(8, 0) * _tmp37 + P(8, 1) * _tmp38 + P(8, 2) * _tmp39 + P(8, 21) * _tmp47 +
                  P(8, 22) * _tmp48 + P(8, 3) * _tmp42 + P(8, 4) * _tmp45 + P(8, 5) * _tmp46);
    _k(9, 0) =
        _tmp49 * (P(9, 0) * _tmp37 + P(9, 1) * _tmp38 + P(9, 2) * _tmp39 + P(9, 21) * _tmp47 +
                  P(9, 22) * _tmp48 + P(9, 3) * _tmp42 + P(9, 4) * _tmp45 + P(9, 5) * _tmp46);
    _k(10, 0) =
        _tmp49 * (P(10, 0) * _tmp37 + P(10, 1) * _tmp38 + P(10, 2) * _tmp39 + P(10, 21) * _tmp47 +
                  P(10, 22) * _tmp48 + P(10, 3) * _tmp42 + P(10, 4) * _tmp45 + P(10, 5) * _tmp46);
    _k(11, 0) =
        _tmp49 * (P(11, 0) * _tmp37 + P(11, 1) * _tmp38 + P(11, 2) * _tmp39 + P(11, 21) * _tmp47 +
                  P(11, 22) * _tmp48 + P(11, 3) * _tmp42 + P(11, 4) * _tmp45 + P(11, 5) * _tmp46);
    _k(12, 0) =
        _tmp49 * (P(12, 0) * _tmp37 + P(12, 1) * _tmp38 + P(12, 2) * _tmp39 + P(12, 21) * _tmp47 +
                  P(12, 22) * _tmp48 + P(12, 3) * _tmp42 + P(12, 4) * _tmp45 + P(12, 5) * _tmp46);
    _k(13, 0) =
        _tmp49 * (P(13, 0) * _tmp37 + P(13, 1) * _tmp38 + P(13, 2) * _tmp39 + P(13, 21) * _tmp47 +
                  P(13, 22) * _tmp48 + P(13, 3) * _tmp42 + P(13, 4) * _tmp45 + P(13, 5) * _tmp46);
    _k(14, 0) =
        _tmp49 * (P(14, 0) * _tmp37 + P(14, 1) * _tmp38 + P(14, 2) * _tmp39 + P(14, 21) * _tmp47 +
                  P(14, 22) * _tmp48 + P(14, 3) * _tmp42 + P(14, 4) * _tmp45 + P(14, 5) * _tmp46);
    _k(15, 0) =
        _tmp49 * (P(15, 0) * _tmp37 + P(15, 1) * _tmp38 + P(15, 2) * _tmp39 + P(15, 21) * _tmp47 +
                  P(15, 22) * _tmp48 + P(15, 3) * _tmp42 + P(15, 4) * _tmp45 + P(15, 5) * _tmp46);
    _k(16, 0) =
        _tmp49 * (P(16, 0) * _tmp37 + P(16, 1) * _tmp38 + P(16, 2) * _tmp39 + P(16, 21) * _tmp47 +
                  P(16, 22) * _tmp48 + P(16, 3) * _tmp42 + P(16, 4) * _tmp45 + P(16, 5) * _tmp46);
    _k(17, 0) =
        _tmp49 * (P(17, 0) * _tmp37 + P(17, 1) * _tmp38 + P(17, 2) * _tmp39 + P(17, 21) * _tmp47 +
                  P(17, 22) * _tmp48 + P(17, 3) * _tmp42 + P(17, 4) * _tmp45 + P(17, 5) * _tmp46);
    _k(18, 0) =
        _tmp49 * (P(18, 0) * _tmp37 + P(18, 1) * _tmp38 + P(18, 2) * _tmp39 + P(18, 21) * _tmp47 +
                  P(18, 22) * _tmp48 + P(18, 3) * _tmp42 + P(18, 4) * _tmp45 + P(18, 5) * _tmp46);
    _k(19, 0) =
        _tmp49 * (P(19, 0) * _tmp37 + P(19, 1) * _tmp38 + P(19, 2) * _tmp39 + P(19, 21) * _tmp47 +
                  P(19, 22) * _tmp48 + P(19, 3) * _tmp42 + P(19, 4) * _tmp45 + P(19, 5) * _tmp46);
    _k(20, 0) =
        _tmp49 * (P(20, 0) * _tmp37 + P(20, 1) * _tmp38 + P(20, 2) * _tmp39 + P(20, 21) * _tmp47 +
                  P(20, 22) * _tmp48 + P(20, 3) * _tmp42 + P(20, 4) * _tmp45 + P(20, 5) * _tmp46);
    _k(21, 0) =
        _tmp49 * (P(21, 0) * _tmp37 + P(21, 1) * _tmp38 + P(21, 2) * _tmp39 + P(21, 21) * _tmp47 +
                  P(21, 22) * _tmp48 + P(21, 3) * _tmp42 + P(21, 4) * _tmp45 + P(21, 5) * _tmp46);
    _k(22, 0) =
        _tmp49 * (P(22, 0) * _tmp37 + P(22, 1) * _tmp38 + P(22, 2) * _tmp39 + P(22, 21) * _tmp47 +
                  P(22, 22) * _tmp48 + P(22, 3) * _tmp42 + P(22, 4) * _tmp45 + P(22, 5) * _tmp46);
    _k(23, 0) =
        _tmp49 * (P(23, 0) * _tmp37 + P(23, 1) * _tmp38 + P(23, 2) * _tmp39 + P(23, 21) * _tmp47 +
                  P(23, 22) * _tmp48 + P(23, 3) * _tmp42 + P(23, 4) * _tmp45 + P(23, 5) * _tmp46);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym