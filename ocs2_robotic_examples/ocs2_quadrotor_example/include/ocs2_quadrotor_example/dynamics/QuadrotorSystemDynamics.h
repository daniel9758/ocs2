/******************************************************************************
Copyright (c) 2020, Farbod Farshidian. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

 * Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#pragma once

#include <ocs2_core/dynamics/SystemDynamicsBase.h>

#include "ocs2_quadrotor_example/QuadrotorParameters.h"
#include "ocs2_quadrotor_example/definitions.h"

namespace ocs2 {
namespace quadrotor {

class QuadrotorSystemDynamics final : public SystemDynamicsBase {
 public:
  /**
   * Constructor
   *
   * @param quadrotorParameters: Quadrotor parameters.
   */
  QuadrotorSystemDynamics(const QuadrotorParameters& quadrotorParameters)
      : SystemDynamicsBase(STATE_DIM_, INPUT_DIM_), param_(quadrotorParameters) {}

  /** Destructor */
  ~QuadrotorSystemDynamics() override = default;

  QuadrotorSystemDynamics* clone() const override { return new QuadrotorSystemDynamics(*this); }

  vector_t computeFlowMap(scalar_t time, const vector_t& state, const vector_t& input) override;
  void setCurrentStateAndControl(scalar_t t, const vector_t& x, const vector_t& u) override;
  matrix_t getFlowMapDerivativeState() override;
  matrix_t getFlowMapDerivativeInput() override;

 private:
  QuadrotorParameters param_;

  matrix_t jacobianOfAngularVelocityMapping_;
};

}  // namespace quadrotor
}  // namespace ocs2
