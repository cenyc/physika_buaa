/*
 * @file PDM_step_method_state_viscoplasticiy_semi_implicit.h 
 * @Basic PDMStepMethodStateViscoPlasticitySemiImplicit class.
 * @author Wei Chen
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#ifndef PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_STEP_METHOD_STATE_VISCOPLASTICITY_SEMI_IMPLICIT_H
#define PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_STEP_METHOD_STATE_VISCOPLASTICITY_SEMI_IMPLICIT_H

#include "Physika_Dynamics/PDM/PDM_Step_Methods/PDM_step_method_state_viscoplasticity.h"

namespace Physika{

template <typename Scalar, int Dim>
class PDMStepMethodStateViscoPlasticitySemiImplicit: public PDMStepMethodStateViscoPlasticity<Scalar, Dim>
{
public:
    PDMStepMethodStateViscoPlasticitySemiImplicit();
    PDMStepMethodStateViscoPlasticitySemiImplicit(PDMState<Scalar, Dim> * pdm_base);
    virtual ~PDMStepMethodStateViscoPlasticitySemiImplicit();

    virtual  void advanceStep(Scalar dt);

};

}// end of namespace Physika

#endif //PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_STEP_METHOD_STATE_VISCOPLASTICITY_SEMI_IMPLICIT_H