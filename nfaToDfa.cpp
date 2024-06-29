#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

struct NFAState {
    map<char, set<int>> transitions; // Transitions on input symbols
    set<int> epsilonTransitions;     // Epsilon transitions
};

struct DFAState {
    set<int> nfaStates;
};

void addTransition(NFAState& state, char input, int nextState) {
    state.transitions[input].insert(nextState);
}

void addEpsilonTransition(NFAState& state, int nextState) {
    state.epsilonTransitions.insert(nextState);
}

set<int> epsilonClosure(const set<int>& startStates, const vector<NFAState>& nfa) {
    set<int> closure = startStates;
    vector<int> stack(startStates.begin(), startStates.end());

    while (!stack.empty()) {
        int current = stack.back();
        stack.pop_back();

        for (int nextState : nfa[current].epsilonTransitions) {
            if (closure.insert(nextState).second) {
                stack.push_back(nextState);
            }
        }
    }
    return closure;
}

set<int> transition(const set<int>& states, char symbol, const vector<NFAState>& nfa) {
    set<int> result;
    for (int state : states) {
        auto it = nfa[state].transitions.find(symbol);
        if (it != nfa[state].transitions.end()) {
            result.insert(it->second.begin(), it->second.end());
        }
    }
    return epsilonClosure(result, nfa);
}

vector<DFAState> convertNFAtoDFA(const vector<NFAState>& nfa, int startState, const set<char>& alphabet) {
    vector<DFAState> dfa;
    map<set<int>, int> stateMapping;

    set<int> startStates;
    startStates.insert(startState);
    set<int> startClosure = epsilonClosure(startStates, nfa);
    stateMapping[startClosure] = 0;
    dfa.push_back({startClosure});

    for (size_t i = 0; i < dfa.size(); ++i) {
        const set<int>& currentState = dfa[i].nfaStates;

        for (char c : alphabet) {
            set<int> newState = transition(currentState, c, nfa);

            if (!newState.empty() && stateMapping.find(newState) == stateMapping.end()) {
                stateMapping[newState] = dfa.size();
                dfa.push_back({newState});
            }
        }
    }

    return dfa;
}

void printDfaTable(const vector<DFAState>& dfa, const set<char>& alphabet, const vector<NFAState>& nfa) {
    cout << "DFA Transition Table:" << endl;
    cout << "DFA State\t|\t";
    for (char c : alphabet) {
        cout << c << "\t";
    }
    cout << endl;

    for (size_t i = 0; i < dfa.size(); i++) {
        cout << "DFA State " << i << "\t|\t";
        for (char c : alphabet) {
            set<int> result = transition(dfa[i].nfaStates, c, nfa);
            if (!result.empty()) {
                // Here, find the DFA state corresponding to the NFA state set
                for (size_t j = 0; j < dfa.size(); j++) {
                    if (dfa[j].nfaStates == result) {
                        cout << j << "\t";
                        break;
                    }
                }
            } else {
                cout << "-\t";
            }
        }
        cout << endl;
    }
}


int main() {
    int numStates;
    cout << "Enter the number of states in the NFA: ";
    cin >> numStates;

    vector<NFAState> nfa(numStates);
    set<char> alphabet;
    int numAlphabets;
    cout << "Enter the number of alphabets (excluding epsilon): ";
    cin >> numAlphabets;

    cout << "Enter the alphabets (one character each): ";
    for (int i = 0; i < numAlphabets; ++i) {
        char symbol;
        cin >> symbol;
        alphabet.insert(symbol);
    }

    int numTransitions;
    cout << "Enter the number of transitions: ";
    cin >> numTransitions;
    cout << "Enter transitions in the format: [state] [input] [next state]. Use 'e' for epsilon transitions.\n";
    
    for (int i = 0; i < numTransitions; ++i) {
        int state, nextState;
        char input;
        cin >> state >> input >> nextState;
        if (input == 'e') {
            addEpsilonTransition(nfa[state], nextState);
        } else {
            addTransition(nfa[state], input, nextState);
        }
    }

    int startState;
    cout << "Enter the start state: ";
    cin >> startState;

    int numAcceptStates;
    cout << "Enter the number of accept states: ";
    cin >> numAcceptStates;
    set<int> acceptStates;
    cout << "Enter the accept states: ";
    for (int i = 0; i < numAcceptStates; ++i) {
        int acceptState;
        cin >> acceptState;
        acceptStates.insert(acceptState);
    }

    // Converting NFA to DFA
    vector<DFAState> dfa = convertNFAtoDFA(nfa, startState, alphabet);

    // Print DFA Table
    printDfaTable(dfa, alphabet, nfa);

    return 0;
}