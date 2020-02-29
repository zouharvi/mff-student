# (Weighted) Finite-State Transducers

## 1. Introduction
- general way of representing HMMs
- lots of established techniques/operatoins for working with automata/FST
- FST is a finite automaton with edges, that both input and output
- weighted transducer adds weights to edges (not necessarily probabilities, e.g. durations, penalties)

## 2. Definitions and Algorithms
- semiring (set, associative and commutative operation +, associative operation \*, +, \* identities, distributivity)
- probability semiring (R, +, \*, 0, 1)
- -log (R, +, \*, 0, 1) for implementation purposes, called log semiring  
- when doing Viterbi, we use (R_{+, \inf}, min, +, inf, 0)

### 2.1 Weighted Acceptors
- WFSA is given by:
- - semiring K
- - alphabet \Sigma
- - set of states Q
- - set of transitions E (even for epsilon transitions)
- - accepting states F
- - weights \lambda
- - final weight function \ro (used for final states)
- transition is (source state, symbol, weight, next state) (in ASR, the weight is usually -log prob) 
- a path is a sequence of transitions with matching states
- a successful path is a path from the initial state to any accepting state
- the weight associated to a transition is a \* product of the weights and the final weight function
- weight of a string is a + sum of the weights of all successful paths for this string
- a generaliation of HMMs

### 2.2 Weighted Transducers
- WFST is given similarly as WFSA, but the transition label is a pair of input and output symbol
- path output label is the concatenation of the output symbols
- creates a mapping

### 2.3 Weighted Transducer Algorithms
- many systems are tied to a specific topology/properties
- proposed the most generic system for WFST, which encapsulates all tasks and approaches
- operations:
- - union, concatenation, repetition: simple
- - determinization: at most one transition from a state for a given symbol and no epsilon transitions
- - minimization: equivalent language, but smaller automaton
- - converting transducers to acceptors

## 3. WFST Applications
### 3.1 Combination
- each state in one automaton expands to the second automaton
- N\*M states
- context-dependent transducers can be combined with others to create more complex systems

### 3.2 Transducer Standardization
- determinization, minimization, factoring
- first-pass transducers
- - 7208 distinct HMM states, each with an emission mixture distribution of up to 12 Gaussians
- - triphonic context-dependency transducer C with 1,525 states and 80,225 transitions
- - 40k word pronunciation dictionary
- - trigram language model
- - application of operations on transducers and the resulting number of states & transitions in table 1
- - 83% word accuracy after one-pass viterbi decoder
- rescoring transducers
- - lattice ???

### 3.3 Recognizer Combination
- basically ensembling, which somewhat improved the word accuracy
