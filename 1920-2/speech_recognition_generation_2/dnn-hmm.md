# 6.1 DNN-HMM Hybrid Systems

## ANN-HMM
- speech dynamics with HMM, observation probabilities with DNNs P(state, class|observation)
- how are the ANN parameters estimated?

## CD-DNN-HMM
- DNN predicts P(q=state|observation), but is actually fed a frame, usually 9-13
- we actually want P(observation|q=state) = p(q=state|observation)p(observation)/p(q=state)
- p(q=state) = #s / total (from training data)
- p(observation) can be ignored (because we are probably using argmax)
- add a language model p(w)
- add a balancing lambda constant
- w = argmax (log(p(x|w)) + lambda log(p(w)))

### Training
- bootstrapped using GMM-HMM
- by including neighboring frames the DNN model correlations between features and thus partially alleviates the violation to the observaion assumption made in HMM

### Evaluation
- Bing Mobile Voice Search: SER instead of WER (avergate sentence length is 2.1)
- Switchboard: ... 
- Neighboring Frames ...
- Pretraining ...
