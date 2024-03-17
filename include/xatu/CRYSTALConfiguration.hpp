#pragma once
#include "xatu/SystemConfiguration.hpp"


typedef std::vector<std::vector<std::vector<double>>> cube_vector;

namespace xatu {

class CRYSTALConfiguration : public SystemConfiguration {

    public:
        int ndim, natoms, norbitals, nsh, nspecies;
        int totalElectrons, coreElectrons;
        bool SOC_FLAG = false;
        bool MAGNETIC_FLAG = false;
        bool alpha_electrons = true;
        
        arma::mat motif, bravaisLattice;
        
        std::vector<int> atomic_number_ordering;
        std::vector<int> shellsPerSpecies;
        std::vector<int> orbitalsPerSpecies;
        // std::map<int, std::vector<std::string>> shellTypesPerSpecies;
        std::map<int, cube_vector> gaussianCoefficients;

        arma::mat bravaisVectors;
        arma::cx_cube overlapMatrices, fockMatrices;
        arma::cx_cube alphaMatrices, betaMatrices;

    public:
        CRYSTALConfiguration(std::string, int ncells);
        ~CRYSTALConfiguration(){};


        void parseContent(int);

    private:
        void parseBravaisLattice();
        void parseAtoms();
        void parseAtomicBasis();
        arma::cx_mat parseMatrix();
        void extractDimension();
    
    protected:
        void mapContent(bool debug = false);
        
};

size_t split(const std::string&, std::vector<double>&);

}
