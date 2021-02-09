#include "ContingencyTable.hh"
#include "AntecedentGenerator.hh"
#include "oden/odenUtils/odenUtils.hh"
#include "supportMethods.hh"
#include <iomanip>
#include <locale>

using namespace std;
using namespace oden;

namespace ateam {


    ContingencyTable::ContingencyTable(Assertion* assertion) {
        this->assertion = assertion;
        this->table[this->ANTECEDENT_FALSE][this->CONSEQUENT_FALSE] = 0;
        this->table[this->ANTECEDENT_FALSE][this->CONSEQUENT_TRUE] = 0;
        this->table[this->ANTECEDENT_TRUE][ this->CONSEQUENT_FALSE] = 0;
        this->table[this->ANTECEDENT_TRUE][ this->CONSEQUENT_TRUE] = 0;
        this->evaluate();
    }

    void ContingencyTable::evaluate() {
        Proposition* antecedent = this->assertion->antecedent;
        Proposition* consequent = this->assertion->consequent;
        const int trace_time = antecedent->getMaxTime();
        
        for(int i = 0; i < trace_time; i++) {
            // valuto antecedente e conseguente
            bool a = antecedent->evaluate(i);
            bool c = consequent->evaluate(i);
            // riempio la tabella di contingenza
            table[a?ANTECEDENT_TRUE:ANTECEDENT_FALSE][c?CONSEQUENT_TRUE:CONSEQUENT_FALSE]++;
        }
    }

    int ContingencyTable::f(pos antecedente, pos conseguente) {
        int antT_conT = table[ANTECEDENT_TRUE][CONSEQUENT_TRUE], 
            antT_conF = table[ANTECEDENT_TRUE][CONSEQUENT_FALSE], 
            antF_conT = table[ANTECEDENT_FALSE][CONSEQUENT_TRUE], 
            antF_conF = table[ANTECEDENT_FALSE][CONSEQUENT_FALSE];
        if(antecedente == T) {
            if(conseguente == T) {
                return antT_conT;
            } else if(conseguente == F) {
                return antT_conF;
            } else { // D 
                return antT_conT + antT_conF;
            }
        } else if(antecedente == F) {
            if(conseguente == T) {
                return antF_conT;
            } else if(conseguente == F) {
                return antF_conF;
            } else { // D 
                return antF_conT + antF_conF;
            }
        } else { // antecedente DONTCARE
            if(conseguente == T) {
                return antT_conT + antF_conT;
            } else if(conseguente == F) {
                return antT_conF + antF_conF;
            } else {
                return antT_conT + antT_conF + antF_conT + antF_conF; 
            }
        }
    }

    void ContingencyTableAnalysis::add_assertion(Assertion* assertion) {
        assertions.push_back(assertion);
    }



    void ContingencyTableAnalysis::export_all(string output_filename) {

        ofstream file;
        file.open (output_filename);
        file.imbue(std::locale( "" ));
        file << "ASSERTION" << ";" << "AT/CT" << ";" << "AT/CF" << ";" << "AF/CT" << ";" << "AF/CF" << ";" 
             << "CORRELATION;" << "KAPPA;" << "COSINE;" << "PIATETSKY;" << "ALL-CONFIDENCE;" << "GOODMAN_KRUSKAL;" << "MUTUAL_INFO;" 
             << "GINI-INDEX;" << "LAPLACE;" << "ADDED_VALUE;" << "SCORE;" << "Number of Literals;" << "Offset_Next;" << endl;

        for(auto i = assertions.begin(); i != assertions.end(); i++) {
            Assertion* assertion = *i;
            ContingencyTable ct(assertion);

            Proposition* antecedent = assertion->antecedent;
            Proposition* consequent = assertion->consequent;

            /*auto *maybeNext = dynamic_cast<PropositionNext*>(consequent);
            
            int offset_next;
            if (maybeNext == nullptr)
                offset_next = 0;
            else {
                offset_next = maybeNext->getOffset();
            }*/


            string assertion_representation = oden::prop2String(*antecedent) + " -> " + oden::prop2String(*consequent);
            file << assertion_representation << ";" << setw(6) << ct.f(T,T) << ";" << ct.f(T,F) << ";" << ct.f(F,T) << ";" << ct.f(F,F) << ";" 
                 << setprecision(5) << fixed << correlation(ct) << ";"
                 << setprecision(5) << kappa(ct) << ";"
                 //<< setprecision(5) << interest(ct) << ";"
                 << setprecision(5) << cosine(ct) << ";"
                 << setprecision(5) << piatetsky(ct) << ";"
                 //<< setprecision(5) << jaccard(ct) << ";"
                 << setprecision(5) << AllConfidence(ct) << ";"
                 << setprecision(5) << goodman_kruskal(ct) << ";"
                 << setprecision(5) << mutual_information(ct) << ";"
                 //<< setprecision(5) << j_measure(ct) << ";"
                 << setprecision(5) << gini_index(ct) << ";"
                 << setprecision(5) << laplace(ct) << ";"
                 //<< setprecision(5) << conviction(ct) << ";"
                 //<< setprecision(5) << certainty_factor(ct) << ";"
                 << setprecision(5) << added_value(ct) << ";"
                 << setprecision(5) << score_cluster(ct) << ";"
                 << setprecision(5) << oden::prop2len(*antecedent) << ";"
                 << setprecision(5) << oden::prop2next(*consequent)  << ";"
                 << endl;
        }

        file.close();
        cout << "Exported on file " << output_filename << endl;
    }

    void ContingencyTableAnalysis::print_all() {
        /*
        cout << endl;
        cout << "| -------------------------------------------------------------- CONTINGENCY TABLE & METRICS ------------------------------------------------------------------------- |" << endl;
        cout << "| " << setw(35) << "ASSERTION" << " | " << setw(6) << "AT/CT" << " | " << setw(6) << "AT/CF" << " | " << setw(6) << "AF/CT" << " | " << setw(6) << "AF/CF" 
            << " | " << setw(11) << "CORRELATION" << " | " << setw(11) << "KAPPA" << " | " << setw(11) << "COSINE" << " | " << setw(11) << "PIATETSKY" 
            << " | " << setw(11) << "ALL-CONFI" << " | " << setw(11) << "G_KRUSKAL" << setw(12) << " | " << endl;
        
        for(auto i = assertions.begin(); i != assertions.end(); i++) {
            Assertion* assertion = *i;
            ContingencyTable ct(assertion);

            Proposition* antecedent = assertion->antecedent;
            Proposition* consequent = assertion->consequent;
            string assertion_representation = oden::prop2String(*antecedent) + " -> " + oden::prop2String(*consequent);
            cout << "| " << setw(35) << assertion_representation << " | " << setw(6) << ct.f(T,T) << " | " << setw(6) << ct.f(T,F) << " | " << setw(6) << ct.f(F,T) << " | " << setw(6) << ct.f(F,F) 
                << " | " << setw(11) << setprecision(5) << fixed << correlation(ct)
                << " | " << setw(11) << setprecision(5) << kappa(ct)
                //<< " | " << setw(11) << setprecision(5) << interest(ct) 
                << " | " << setw(11) << setprecision(5) << cosine(ct)
                << " | " << setw(11) << setprecision(5) << piatetsky(ct)
                //<< " | " << setw(11) << setprecision(5) << jaccard(ct)
                << " | " << setw(11) << setprecision(5) << AllConfidence(ct)
                << " | " << setw(11) << setprecision(5) << goodman_kruskal(ct) << setw(11) << "|" << endl;
        }
        cout << "| -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |" << endl << endl;
    

        cout << endl;
        cout << "| ------------------------------------------------------- CONTINGENCY TABLE & METRICS ---------------------------------------------------- |" << endl;
        cout << "| " << setw(35) << "ASSERTION" << " | " << setw(6) << "AT/CT" << " | " << setw(6) << "AT/CF" << " | " << setw(6) << "AF/CT" << " | " << setw(6) << "AF/CF" 
            << " | " << setw(11) << "MUTUAL_INFO" << " | " << setw(11) << "GINI-INDEX" <<" | " << setw(11) << "LAPLACE" << " | " 
            << setw(11) << "ADDED_VALUE" << setw(12) << " | " << endl;

        for(auto i = assertions.begin(); i != assertions.end(); i++) {
            Assertion* assertion = *i;
            ContingencyTable ct(assertion);

            Proposition* antecedent = assertion->antecedent;
            Proposition* consequent = assertion->consequent;
            string assertion_representation = oden::prop2String(*antecedent) + " -> " + oden::prop2String(*consequent);
            cout << "| " << setw(35) << assertion_representation << " | " << setw(6) << ct.f(T,T) << " | " << setw(6) << ct.f(T,F) << " | " << setw(6) << ct.f(F,T) << " | " << setw(6) << ct.f(F,F) 
                << " | " << setw(11) << setprecision(5) << mutual_information(ct) 
                //<< " | " << setw(11) << setprecision(5) << j_measure(ct) 
                << " | " << setw(11) << setprecision(5) << gini_index(ct) //gini_index(ct) 
                << " | " << setw(11) << setprecision(5) << laplace(ct) //laplace(ct) 
                //<< " | " << setw(11) << setprecision(5) << conviction(ct) 
                //<< " | " << setw(11) << setprecision(5) << certainty_factor(ct) 
                << " | " << setw(11) << setprecision(5) << added_value(ct) << setw(11) << "|" << endl;
        }
        cout << "| ---------------------------------------------------------------------------------------------------------------------------------------- |" << endl << endl;
        */
        for(auto i = assertions.begin(); i != assertions.end(); i++) {
            Assertion* assertion = *i;
            ContingencyTable ct(assertion);

            Proposition* antecedent = assertion->antecedent;
            Proposition* consequent = assertion->consequent;
//            cout << "SCORE: " << score_cluster(ct) << "     Letterali: " << oden::prop2len(*antecedent) << endl; //size(assertions->antecedent) << endl;
            

            auto *maybeNext = dynamic_cast<PropositionNext*>(consequent);
            
 //           if (maybeNext == nullptr)
 //               cout << "Next: " << 0 << endl;
 //           else {
 //               cout << "Next: " << maybeNext->getOffset() << endl;
 //           }








        }
    }





    ContingencyTableAnalysis::ContingencyTableAnalysis() : assertions() {
    }

    double ContingencyTableAnalysis::score_cluster(ContingencyTable ct){
        int alfa = 4;
        int beta = 1;
        int gamma = 1;
        double score = (alfa*ct.f(T,T)+beta*ct.f(F,F)-gamma*ct.f(F,T)) / (ct.f(D,D)*1.0);
        return score;
    }

    /*
    double ContingencyTableAnalysis::letteral_count (ContingencyTable ct){


        return count;
    }*/







    double ContingencyTableAnalysis::correlation(ContingencyTable ct) {
        /* LIBRO DATA MINING */
        
        
        double N = ct.f(D,D)*1.0;
        double numeratore = N*ct.f(T,T) - ct.f(T,D)*ct.f(D,T);

        /* DA MOLTIPLICARE COSÌ PER EVITARE OVERFLOW */
        double radice = 1.0 * ct.f(D,T);
        radice = radice * ct.f(D,F);
        radice = radice * ct.f(T,D);
        radice = radice * ct.f(F,D);
        double denominatore = sqrt(radice);

        return numeratore / denominatore;
        

        /* CORRELAZIONE ALTERNATIVA 
        int N = ct.f(D,D);
        double numeratore = N*ct.f(T,T) - ct.f(T,D)*ct.f(D,T);

        double sommatoria_x = ct.f(T,D);
        double sommatoria_y = ct.f(D,T);

        double sommatoria_x_2 = ( ct.f(T,F) * ct.f(T,F) ) + ( ct.f (T,T) * ct.f(T,T) );
        double sommatoria_y_2 = ( ct.f(F,T) * ct.f(F,T) ) + ( ct.f (T,T) * ct.f(T,T) );

        double denominatore = sqrt( ( N* sommatoria_x_2 - sommatoria_x * sommatoria_x) * (N* sommatoria_y_2 - sommatoria_y * sommatoria_y) );

        return numeratore / denominatore;*/

    }

    double ContingencyTableAnalysis::kappa(ContingencyTable ct) {
        int N = ct.f(D,D); 
        return (1.0 * N * ct.f(T,T) + N * ct.f(F,F) - ct.f(T,D) * ct.f(D,T) - ct.f(F,D) * ct.f(D,F) ) 
                 / (N * N - ct.f(T,D) * ct.f(D,T) - ct.f(F,D) * ct.f(D,F) );
    }

    double ContingencyTableAnalysis::interest(ContingencyTable ct) {
        int N = ct.f(D,D);
        double numeratore = N * ct.f(T,T);
        double denominatore = ct.f(T,D) * ct.f(D,T);
        return numeratore / denominatore;
    }

    double ContingencyTableAnalysis::cosine(ContingencyTable ct) {
        double numeratore = ct.f(T,T);
        double denominatore = sqrt (ct.f(T,D) * ct.f(D,T));
        return numeratore / denominatore;
    }

    double ContingencyTableAnalysis::piatetsky(ContingencyTable ct) {
        int N = ct.f(D,D);
        double primo = ct.f(T,T)/(N*1.0);
        double secondo = (ct.f(T,D) * ct.f(D,T)) / (N*N*1.0);
        return (primo - secondo) * 4.0;
    }

    double ContingencyTableAnalysis::jaccard(ContingencyTable ct) {
        double numeratore = ct.f(T,T); 
        double denominatore = ct.f(T,D) + ct.f(D,T) - ct.f(T,T);
        return numeratore / denominatore;
    }

    double ContingencyTableAnalysis::AllConfidence(ContingencyTable ct) {
        double primo = ct.f(T,T) / (ct.f(T,D) * 1.0);
        double secondo = ct.f(T,T) / (ct.f(D,T) * 1.0);
        return min(primo,secondo);
    }



    double ContingencyTableAnalysis::goodman_kruskal(ContingencyTable ct) {
        double N = 1.0 * ct.f(D,D);
        double numeratore = 1.0 * max( ct.f(T,T), ct.f(T,F) ) + max( ct.f(F,T), ct.f(F,F) ) - max( ct.f(D,T), ct.f(D,F));
        double denominatore = N - max( ct.f(D,T), ct.f(D,F) );
        return numeratore / denominatore;
    }

    double ContingencyTableAnalysis::mutual_information(ContingencyTable ct) {
        double N = 1.0 * ct.f(D,D) ;
        pos pos_array[2] = { T, F };

        double numeratore = 0;
        // calcolo del numeratore
        for(size_t i = 0; i < 2; i++) {

            for(size_t j = 0; j < 2; j++) {
                pos pos_i = pos_array[i], pos_j = pos_array[j];
                double first_term = 1.0 * ct.f(pos_i, pos_j) / N;
                double second_term = (1.0 * N * ( ct.f(pos_i, pos_j) + 1)) / (ct.f(pos_i, D) * ct.f(D, pos_j));
                second_term = log(second_term);

                numeratore += first_term * second_term;
            }
        }
        double denominatore = 0;
        // calcolo del denominatore
        for(size_t i = 0; i < 2; i++) {

            pos pos_i = pos_array[i];
            double term = ct.f(pos_i, D) / N;
            term = term * log(term);

            denominatore += term;
        }
        denominatore *= -1; // c'è il - davanti

        return numeratore / denominatore;
    }

    // DISCARD
    double ContingencyTableAnalysis::j_measure(ContingencyTable ct) {
        double N = 1.0 * ct.f(D,D);
        double first_term = (ct.f(T,T) / N) * log( (N * ct.f(T,T)) / (ct.f(T,D) * ct.f(D,T)) );
        double second_term = (ct.f(T,F) / N) * log( (N * ct.f(T,F)) / (ct.f(T,D) * ct.f(D,F)) );
        return first_term + second_term;
    }

    double ContingencyTableAnalysis::gini_index(ContingencyTable ct) {
        double N = 1.0 * ct.f(D,D);
        double xx = ct.f(T,T) / ct.f(T,D),
                xy = ct.f(T,F) / ct.f(T,D),
                yx = ct.f(F,T) / ct.f(F,D),
                yy = ct.f(F,F) / ct.f(F,D);
        double first_term = ct.f(T,D) / N * ( pow(xx, 2) + pow(xy, 2) );
        double second_term = pow( ct.f(D,T) / N , 2);
        double third_term = ct.f(F,D) / N * ( pow(yx, 2) + pow(yy, 2) );
        double fourth_term = pow( ct.f(D,F) / N , 2);
        return abs(first_term - second_term + third_term - fourth_term);
    }

    double ContingencyTableAnalysis::laplace(ContingencyTable ct) {
        double numeratore = 1.0 * ct.f(T,T) + 1;
        double denominatore = 1.0 * ct.f(T,D) + 2;
        return numeratore/denominatore;
    }

    // DISCARD
    double ContingencyTableAnalysis::conviction(ContingencyTable ct) {
        double N = 1.0 * ct.f(D,D);
        double numeratore = 1.0 * ct.f(T,D) * ct.f(D,F);
        double denominatore = N * ct.f(T,F);
        return numeratore / denominatore;
    }

    /* Divido una cosa sempre per se stessa-- si ottiene sempre 1*/
    double ContingencyTableAnalysis::certainty_factor(ContingencyTable ct) {
        double second_term = 1.0 * ct.f(D,T) / ct.f(D,D);
        return added_value(ct) / (1.0 - second_term);
    }
    
    double ContingencyTableAnalysis::added_value(ContingencyTable ct) {
        double N = 1.0 * ct.f(D,D);
        double first_term = 1.0 * ct.f(T,T) / ct.f(T,D);
        double second_term = 1.0 * ct.f(D,T) / N;
        return first_term - second_term;
    }

} // namespace ateam
