/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019-2023 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

#include <gtest/gtest.h>
#include "NeulandPointFilter.h"
#include "R3BNeulandPoint.h"
#include <bitset>

namespace 
{

using namespace R3B::Neuland;

// Mock class for R3BNeulandPoint to simulate behavior
class MockR3BNeulandPoint : public R3BNeulandPoint {
public:
    MockR3BNeulandPoint(int pid, double energyLoss)
        : pid_(pid), energyLoss_(energyLoss) {}

    int GetPID() const override { return pid_; }
    double GetEnergyLoss() const override { return energyLoss_; }

private:
    int pid_;
    double energyLoss_;
};

// Test for ParticleToBitSet function
TEST_F(R3BNeulandTest, ParticleToBitSetTest) {
    auto bitset = ParticleToBitSet(BitSetParticle::proton);
    EXPECT_EQ(bitset.to_ulong(), 0x0001);

    bitset = ParticleToBitSet(BitSetParticle::neutron);
    EXPECT_EQ(bitset.to_ulong(), 0x0002);

    bitset = ParticleToBitSet(BitSetParticle::gamma);
    EXPECT_EQ(bitset.to_ulong(), 0x0020);
}

// Test for BitSetToParticle function
TEST_F(R3BNeulandTest, BitSetToParticleTest) {
    auto particle = BitSetToParticle(std::bitset<ParticleBitsetSize>{0x0001});
    EXPECT_EQ(particle, BitSetParticle::proton);

    particle = BitSetToParticle(std::bitset<ParticleBitsetSize>{0x0002});
    EXPECT_EQ(particle, BitSetParticle::neutron);

    particle = BitSetToParticle(std::bitset<ParticleBitsetSize>{0x0020});
    EXPECT_EQ(particle, BitSetParticle::gamma);
}

// Test for CheckCriteria function
TEST_F(R3BNeulandTest, CheckCriteriaTest) {
    EXPECT_TRUE(CheckCriteria(BitSetParticle::proton, BitSetParticle::proton));
    EXPECT_FALSE(CheckCriteria(BitSetParticle::proton, BitSetParticle::neutron));
    EXPECT_TRUE(CheckCriteria(BitSetParticle::proton | BitSetParticle::neutron, BitSetParticle::proton));
}

// Test for PidToBitSetParticle function
TEST_F(R3BNeulandTest, PidToBitSetParticleTest) {
    EXPECT_EQ(PidToBitSetParticle(2212), BitSetParticle::proton);
    EXPECT_EQ(PidToBitSetParticle(2112), BitSetParticle::neutron);
    EXPECT_EQ(PidToBitSetParticle(22), BitSetParticle::gamma);
    EXPECT_EQ(PidToBitSetParticle(999), BitSetParticle::meson);
    EXPECT_EQ(PidToBitSetParticle(123456), BitSetParticle::other);
}

// Test for NeulandPointFilter class
TEST_F(NeulandPointFilterTest, SetFilterTest) {
    NeulandPointFilter filter;
    filter.SetFilter(BitSetParticle::proton);
    EXPECT_EQ(filter.GetFilter(), BitSetParticle::proton);

    filter.SetFilter(BitSetParticle::neutron, 0.5);
    EXPECT_EQ(filter.GetFilter(), BitSetParticle::neutron);
    EXPECT_EQ(filter.GetMinimumAllowedEnergy(), 0.5);
}

// Test for NeulandPointFilter::ShouldNeulandPointBeFiltered function
TEST_F(NeulandPointFilterTest, ShouldNeulandPointBeFilteredTest) {
    NeulandPointFilter filter;
    MockR3BNeulandPoint protonPoint(2212, 1.0); // Proton with 1.0 GeV energy
    MockR3BNeulandPoint neutronPoint(2112, 0.3); // Neutron with 0.3 GeV energy

    // Test filtering criteria for protons
    filter.SetFilter(BitSetParticle::proton);
    EXPECT_TRUE(filter.ShouldNeulandPointBeFiltered(protonPoint));
    EXPECT_FALSE(filter.ShouldNeulandPointBeFiltered(neutronPoint));

    // Test minimum energy filter
    filter.SetFilter(BitSetParticle::neutron, 0.5);
    EXPECT_TRUE(filter.ShouldNeulandPointBeFiltered(neutronPoint)); // Energy is below 0.5
    EXPECT_FALSE(filter.ShouldNeulandPointBeFiltered(protonPoint)); // Energy is above 0.5
}
}
