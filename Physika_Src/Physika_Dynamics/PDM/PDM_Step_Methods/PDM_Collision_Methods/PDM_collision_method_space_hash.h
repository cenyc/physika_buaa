/*
 * @file PDM_collision_method_space_hash.h 
 * @brief class of collision method based on mesh for PDM drivers.
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

#ifndef PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_COLLISION_METHODS_PDM_COLLISION_METHOD_SPACE_HASH_H
#define PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_COLLISION_METHODS_PDM_COLLISION_METHOD_SPACE_HASH_H

namespace Physika{

template <typename Scalar, int Dim>
class PDMCollisionMethodSpaceHash
{
public:
    PDMCollisionMethodSpaceHash();
    ~PDMCollisionMethodSpaceHash();

protected:
};

}// end of namespace Phyaika
#endif //PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_COLLISION_METHODS_PDM_COLLISION_METHOD_SPACE_HASH_H