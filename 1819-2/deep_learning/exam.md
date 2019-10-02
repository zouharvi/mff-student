# Training Neural Network
Compute the values of all weights after performing an SGD update with learning rate `0.1`.
Different networks architectures, activation functions (tanh, sigmoid, softmax) and losses (MSE, NLL) may appear in the exam.

# Maximum Likelihood Estimation
Formulate maximum likelihood estimator for neural network parameters and derive the following two losses:
- NLL (negative log likelihood) loss for networks returning a probability distribution
- MSE (mean square error) loss for networks returning a real number with a normal distribution with a fixed variance

# Backpropagation Algorithm, SGD with Momentum
Write down the backpropagation algorithm. Then, write down the SGD algorithm with momentum. Finally formulate SGD with Nestorov momentum and explain the difference to SGD with regular momentum.

# Adagrad and RMSProp
Write down the AdaGrad algorithm and show that it tends to internally decay learning rate by a factor 1/\sqrt{t}.

# Adam
Write down the Adam algorithm and explain the bias-correction terms (1-\beta^t).

# Regularization
Define overfitting and sketch what a regularization is. Then describe basic regularization methods like early stopping, L2 and L1 regularization, dataset augmentation, ensembling and label smoothing.

# Dropout
Describe the dropout method and write down exactly how is it used during training and during inference. Then explain why it cannot be used on RNN state, describe the variational dropout variant, and also describe layer normalization.

# Network Convergence
Describe factors influencing network convergence, namely:
- Parameter initialization strategies (explain also why batch normalization helps with this issue).
- Problems with saturating non-linearities (and again, why batch normalization helps; you can also discuss why NLL helps with saturating non-linearities on the output layer).
- Gradient clipping (and the difference between clipping individual weights or the gradient as a whole).

# Convolution
Write down equations of how convolution of a given image is computed. Assume the input is an image I of size H×W with CC channels, the kernel KK has size N×M, the stride is T×S, the operation performed is n fact cross-correlation (as usual in convolutional neural networks) and that OO output channels are computed. Explain both SAME and VALID padding schemes and write down output size of the operation for both these padding schemes.

# Batch Normalization
Describe the batch normalization method and explain how it is used during training and during inference. Explicitly write over what is being normalized in case of fully connected layers, and in case of convolutional layers. Compare batch normalization to layer normalization.

# VGG and ResNet
Describe overall architecture of VGG and ResNet (you do not need to remember exact number of layers/filters, but you should know when a BatchNorm is executed, when ReLU, and how residual connections work when the number of channels increases). Then describe two ResNet extensions (WideNet, DenseNet, PyramidNet, ResNeXt).

# Object Detection and Segmentation
Describe object detection and image segmentation tasks, and sketch Fast-RCNN, Faster-RCNN and Mask-RCNN architectures. Notably, show what the overall architectures of the networks are, explain the RoI-pooling and RoI-align layers, show how the network predicts RoI sizes, how do the losses looks like, how are RoI chosen during training and prediction, and what region proposal network does.

# Object Detection
Describe object detection task, and sketch Fast-RCNN, Faster-RCNN and RetinaNet architectures. Notably, show the overall architectures of the networks, explain the RoI-pooling layer, show how the network predicts RoI sizes, how do the losses looks like (classification loss, boundary prediction loss, focal loss for RetinaNet), and what a feature pyramid network is.