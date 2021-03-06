/*
 * @file PDM_collision_method_grid_3d.h 
 * @brief base class of collision method(three dim) for PDM drivers.
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

#ifndef PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_COLLISION_METHODS_PDM_COLLISION_METHOD_GRID_3D_H
#define PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_COLLISION_METHODS_PDM_COLLISION_METHOD_GRID_3D_H

#include <vector>
#include "Physika_Core/Vectors/vector_3d.h"
#include "Physika_Dynamics/PDM/PDM_Step_Methods/PDM_Collision_Methods/PDM_collision_method_base.h"
#include "Physika_Dynamics/PDM/PDM_Step_Methods/PDM_Collision_Methods/PDM_collision_method_grid.h"

namespace Physika{

template <typename Scalar, int Dim> class PDMBase;

template <typename Scalar>
class PDMCollisionMethodGrid<Scalar,3>:public PDMCollisionMethodBase<Scalar,3>
{
public:
    PDMCollisionMethodGrid();
    virtual ~PDMCollisionMethodGrid();

    // setter & getter
    Scalar lambda() const;
    void setLambda(Scalar lambda);

    Vector<Scalar,3> binStartPoint() const;
    void setBinStartPoint(Vector<Scalar,3> bin_start_point);

    Scalar XSpacing() const;
    Scalar YSpacing() const;
    Scalar ZSpacing() const;
    void setXYZSpacing(Scalar x_spacing, Scalar y_spacing, Scalar z_spacing);
    void setUnifySpacing(Scalar spacing);

    unsigned int XBinNum() const;
    unsigned int YBinNum() const;
    unsigned int ZBinNum() const;
    void setXYZBinNum(unsigned int x_bin_num, unsigned int y_bin_num, unsigned int z_bin_num);
    void setUnifyBinNum(unsigned int bin_num);

    virtual void collisionMethod();

    // collision method can also be employed for particle's family initialization to improve performance
    void initParticleFamily(Scalar max_delta);

protected:
    void resetHashBin();
    virtual void locateParticleBin(); // add particle to its own bin
    virtual void collisionDectectionAndResponse();

    unsigned int getHashBinPos(unsigned int x_pos, unsigned int y_pos, unsigned int z_pos);
    bool isOutOfRange(long x_pos, long y_pos, long z_pos);

protected:
    Scalar lambda_;    // minimum inter-particle spacing
    Scalar x_spacing_; // spacing in x axis, at least lambda/2
    Scalar y_spacing_; // spacing in y axis, at least lambda/2
    Scalar z_spacing_; // spacing in z axis, at least lambda/2
    unsigned int x_bin_num_; // number of bin in x axis
    unsigned int y_bin_num_; // number of bin in y axis
    unsigned int z_bin_num_; // number of bin in z axis
    Vector<Scalar, 3> bin_start_point_; // start point of bin

    std::vector<unsigned int> * space_hash_bin_; // hash bin store the idx of particle

};

} // end of namespace Physika

#endif //PHYSIKA_DYNAMICS_PDM_PDM_STEP_METHODS_PDM_COLLISION_METHODS_3D_PDM_COLLISION_METHOD_BASE_H