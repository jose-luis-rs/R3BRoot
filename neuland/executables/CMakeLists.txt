add_executable(neulandSim neulandSim.cxx)
<<<<<<< HEAD
target_link_libraries(neulandSim PRIVATE R3BNeulandSimulation R3BGen ${Geant4_LIBRARIES}
                                         ${Geant4VMC_LIBRARIES})
=======
target_link_libraries(
    neulandSim
    PRIVATE R3BNeulandSimulation
            ExTestDetector
            R3BPassive
            ${Geant4_LIBRARIES}
            geant4vmc
            R3BGen)
>>>>>>> 9cd6ea0c (Implement particle filtering via NeulandPointFilter)

add_executable(neulandAna neulandAna.cxx)
target_link_libraries(neulandAna PRIVATE R3BNeulandDigitizing)
