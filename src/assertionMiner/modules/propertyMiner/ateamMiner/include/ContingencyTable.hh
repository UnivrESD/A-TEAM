#pragma once

#include "oden/Checker.hh"
#include "oden/modules/PropertyMiner.hh"
#include "oden/types.hh"
#include "oden/visitors/visitors.hh"

#include "FaultChecker.hh"
#include "supportTypes.hh"

#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;
using namespace oden;

namespace ateam {

// enum di utilità per prendere i campi
typedef enum { T, F, D } pos;

// struttura della contingency table
class ContingencyTable {

    public:

        ContingencyTable(Assertion* assertion);

        // funzione utilità per prendere agevolmente i campi
        int f(pos antecedente, pos conseguente);

    private:

        // asserzione originale
        Assertion* assertion;

        // contingency table 
        int table[2][2];

        // indici accesso contingency table
        const int ANTECEDENT_TRUE = 1, ANTECEDENT_FALSE = 0;
        const int CONSEQUENT_TRUE = 1, CONSEQUENT_FALSE = 0;

        // valutazione delle asserzioni, riempio contingency table
        void evaluate();
};

// analisi ed esportazione asserzioni
class ContingencyTableAnalysis {

    public: 

        static ContingencyTableAnalysis& instance()
        {
            static ContingencyTableAnalysis the_only_instance; // Guaranteed to be destroyed, nstantiated on first use.
            return the_only_instance;
        }

        void add_assertion(Assertion* assertion);

        void export_all(string output_filename);

        void print_all();

    private: 

        std::vector<Assertion*> assertions;

        ContingencyTableAnalysis();
    
        

        /*
        double oddsRatio(ContingencyTable ct) {
            // ct(T,F) sempre 0
            double numeratore = ct.f(T,T) * ct.f(F,F);
            double denominatore = ct.f(T,F) * ct.f(F,T);
            return numeratore / denominatore;
        }
        */
        
        double correlation(ContingencyTable ct);
        double kappa(ContingencyTable ct);
        double interest(ContingencyTable ct);
        double cosine(ContingencyTable ct);
        double piatetsky(ContingencyTable ct);
        double jaccard(ContingencyTable ct);
        double AllConfidence(ContingencyTable);

        /// @brief: measure of proportional reduction in error in cross tabulation analysis
        double goodman_kruskal(ContingencyTable ct);
        /// @brief:
        double mutual_information(ContingencyTable ct);
        /// @brief:
        double j_measure(ContingencyTable ct);
        /// @brief:
        double gini_index(ContingencyTable ct);
        /// @brief:
        double laplace(ContingencyTable ct);
        /// @brief:
        /// attenzione, divido per N * f(T,F) = 0 ???
        double conviction(ContingencyTable ct);
        /// @brief:
        double certainty_factor(ContingencyTable ct);
        /// @brief:
        double added_value(ContingencyTable ct);

        double score_cluster (ContingencyTable ct);
        double letteral_count (ContingencyTable ct);

};

} // namespace ateam
