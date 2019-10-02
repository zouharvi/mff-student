# finite state automata
## definitions
- DFA, NFA, congruence, automata equivalence
- automata homomorphism
- state equivalence
- left/right quotient/derivation
- language substitution, language homomorphism + inverse
- two way dfa

## theorems
- automata equivalence iff homomorphism
- pumping lemma for regular languages
- n-2n theorem
- Myhill-Nerode theorem
- Kleene theorem
- closure under homomorphism and inverse homomorphism
- two way dfa <=> dfa
- isomorphism of reduced automata

## algorithms
- equivalent state recognition

# grammars
## definitions
- formal generative grammar
- context free grammar
- chomsky hiearchy
- derivation, language of grammar
- parse tree
- left/right derivation
- grammar equivalence
- push down automata, situation
- PDA language
- Chomsky normal form
- Greibach Normal Form

## theorems
- type 3 <=> dfa
- right linear grammar <=> left linear grammar
- left/right derivation <=> derivation <=> exists parse tree
- empty stack <=> accepting states
- CFG <=> PDA
- ChNF <=> CFG
- pumping lemma for context free languages
- m-n for CFL
- GrNF <=> CFG
- CFL closed under substitution, homomorphism, inverse homomorphism
- CFL closed under quotient with RL
- CFL not closed under intersection with CFL, but RL

## algorithms
- CYK

# grammars 2
## definitions
- dyck language
- deterministic PDA
- prefix-free languages
- CFL ambiguity

## theorems
- CFL <=> dyck + RL + homomorphism
- prefix-free languages and DPDA
- DPDA and non-ambiguity

# grammars 3
## definitions
- turing machine, instantenious description, step