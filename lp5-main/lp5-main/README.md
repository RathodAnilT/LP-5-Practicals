**Assignment 1: Parallel BFS and DFS using OpenMP**

**Q1: Define BFS and DFS in graph traversal.**  
- **BFS (Breadth-First Search):** Traverses the graph level by level, visiting all neighbors before going deeper.  
- **DFS (Depth-First Search):** Traverses by going deep along one branch before backtracking.

**Q2: What are the time complexities of BFS and DFS?**  
- **BFS:** O(V + E), where V = vertices, E = edges.  
- **DFS:** O(V + E) for graph traversal as well.

**Q3: How does parallelism improve BFS/DFS performance?**  
- It allows simultaneous exploration of multiple nodes or branches.  
- Reduces traversal time, especially in large graphs.

**Q4: How is a visited array managed safely in parallel BFS?**  
- Use atomic operations to update visited nodes.  
- Critical sections or locks prevent data races.

**Q5: What are critical sections in OpenMP?**  
- Code blocks that only one thread can execute at a time.  
- Ensures data consistency and prevents race conditions.

**Q6: What issues arise when parallelizing DFS?**  
- Hard to divide work dynamically due to its recursive nature.  
- Risk of redundant traversal and synchronization overhead.

**Q7: What is breadth-wise parallelism in BFS?**  
- Parallelizes exploration across all nodes at the current level.  
- Threads process different neighbors of current nodes concurrently.

**Q8: What happens if synchronization is not handled in parallel traversal?**  
- Data races and incorrect traversal results.  
- Possible infinite loops or program crashes.

**Q9: What OpenMP directive is used to parallelize a for loop?**  
- `#pragma omp parallel for` is used.  
- It distributes loop iterations across multiple threads.

**Q10: What are advantages and disadvantages of parallel BFS?**  
- **Advantages:** Faster traversal, better CPU/GPU utilization.  
- **Disadvantages:** Overhead of synchronization, load imbalance.
---

## Assignment 1: Parallel BFS and DFS using OpenMP

**Q1: Define BFS and DFS in graph traversal.**  
- BFS traverses level by level, visiting all immediate neighbors first.  
- DFS traverses by exploring as far down a branch as possible before backtracking.

**Q2: What are the time complexities of BFS and DFS?**  
- BFS: O(V + E) where V = vertices and E = edges.  
- DFS: O(V + E) for traversing the entire graph.

**Q3: How does parallelism improve BFS/DFS performance?**  
- Parallelism explores multiple nodes simultaneously.  
- It reduces total traversal time, especially in large graphs.

**Q4: How is a visited array managed safely in parallel BFS?**  
- Atomic updates ensure no two threads mark the same node incorrectly.  
- Locks or critical sections can also be used for safety.

**Q5: What are critical sections in OpenMP?**  
- A block where only one thread can execute at a time.  
- Prevents race conditions and ensures data consistency.

**Q6: What issues arise when parallelizing DFS?**  
- DFS has recursive dependencies making parallelism hard.  
- It can lead to load imbalance and synchronization problems.

**Q7: What is breadth-wise parallelism in BFS?**  
- Parallel processing of all nodes at the same level.  
- Increases speed by distributing neighbor exploration among threads.

**Q8: What happens if synchronization is not handled in parallel traversal?**  
- Threads might visit the same node multiple times.  
- Leads to wrong results or infinite loops.

**Q9: What OpenMP directive is used to parallelize a for loop?**  
- `#pragma omp parallel for` directive is used.  
- It splits loop iterations among available threads.

**Q10: What are advantages and disadvantages of parallel BFS?**  
- **Advantage:** Faster processing on multi-core systems.  
- **Disadvantage:** High overhead due to thread synchronization.

---

## Assignment 2: Parallel Bubble Sort and Merge Sort using OpenMP

**Q1: Why is Merge Sort called a "divide and conquer" algorithm?**  
- It divides the array into halves recursively.  
- Then conquers by merging sorted halves back together.

**Q2: What happens if two threads try to swap the same elements in parallel Bubble Sort?**  
- Data corruption or incorrect sorting may happen.  
- Synchronization mechanisms are needed to prevent it.

**Q3: How do you divide the array for parallel Merge Sort?**  
- Recursively split the array into independent parts.  
- Assign different parts to different threads.

**Q4: How does OpenMP manage workload among threads?**  
- It dynamically or statically distributes work.  
- Threads pick tasks from a task pool or are assigned ranges.

**Q5: What is the significance of choosing correct grain size?**  
- Balances workload across threads efficiently.  
- Avoids too much overhead from managing tiny tasks.

**Q6: What is the worst-case time complexity of parallel Bubble Sort?**  
- O(n²), similar to serial Bubble Sort.  
- Parallelization may slightly reduce constant factors.

**Q7: How does thread scheduling affect performance in sorting?**  
- Efficient scheduling maximizes CPU usage.  
- Poor scheduling can cause idle time and delays.

**Q8: What is false sharing in parallel sorting?**  
- Multiple threads update variables in the same cache line.  
- Causes performance degradation due to cache coherence overhead.

**Q9: What is memory overhead in Merge Sort and how do you manage it?**  
- Merge Sort needs extra space for merging.  
- Memory can be reused or allocated efficiently to minimize overhead.

**Q10: How would you optimize a parallel sorting algorithm for large datasets?**  
- Use hybrid algorithms combining fast serial sorts at smaller levels.  
- Optimize memory access and minimize synchronization overhead.

---

## Assignment 3: Parallel Reduction Operations using OpenMP

**Q1: What is associative operation? Why is it important for reduction?**  
- Operation where (a+b)+c = a+(b+c).  
- Important because parallel reduction depends on grouping flexibility.

**Q2: What does the reduction clause in OpenMP do internally?**  
- Creates private copies for each thread.  
- Combines results at the end of parallel execution.

**Q3: How do you perform custom reduction operations in OpenMP?**  
- Define user-specific operations with `declare reduction`.  
- Use reduction clauses specifying custom operators.

**Q4: Why might a parallel reduction be slower than serial for small datasets?**  
- Overhead of thread creation and management.  
- Synchronization time outweighs computation gains.

**Q5: Explain the performance impact of cache coherence during reduction.**  
- Frequent cache updates cause slowdowns.  
- False sharing increases coherence traffic.

**Q6: What are atomic operations and how do they differ from reduction?**  
- Atomic operations ensure indivisible updates to shared variables.  
- Reductions combine values more efficiently at end rather than per update.

**Q7: How can thread-local variables help in reduction?**  
- Each thread accumulates its own result.  
- Reduces contention on shared variables.

**Q8: How would you reduce communication overhead during parallel reduction?**  
- Aggregate results locally before combining globally.  
- Use hierarchical reduction structures.

**Q9: In what scenarios is reduction critical for scientific computing?**  
- Summing large vectors/matrices.  
- Calculating global statistics like mean, max, or norms.

**Q10: What are the common pitfalls when writing reduction code in OpenMP?**  
- Missing private copies leads to race conditions.  
- Incorrect combination logic produces wrong results.

---

## Assignment 4: CUDA Programming: Vector Addition and Matrix Multiplication

**Q1: What is the structure of a CUDA program?**  
- Host code to manage device memory and launch kernels.  
- Device code (kernels) to run parallel tasks on GPU.

**Q2: What is a CUDA kernel launch configuration syntax?**  
- `kernel<<<gridSize, blockSize>>>(arguments)` format.  
- Specifies how many threads and blocks to use.

**Q3: How is memory allocated on GPU?**  
- Using `cudaMalloc` to allocate memory.  
- Free memory later with `cudaFree`.

**Q4: What are global, shared, and local memories in CUDA?**  
- Global: Accessible by all threads.  
- Shared: Shared by threads in a block; Local: Private to each thread.

**Q5: How is thread indexing done in a CUDA kernel?**  
- Using threadIdx, blockIdx, blockDim.  
- Overall index = blockIdx * blockDim + threadIdx.

**Q6: What happens if too many threads are launched in CUDA?**  
- Device runs out of resources (registers, shared memory).  
- Kernel launch fails or performance degrades.

**Q7: What is warp size in CUDA?**  
- 32 threads grouped for execution.  
- Threads in a warp execute together.

**Q8: How does coalesced memory access improve performance?**  
- Threads access contiguous memory locations.  
- Reduces memory access latency and boosts bandwidth.

**Q9: What are CUDA streams and why are they useful?**  
- Allow concurrent kernel execution and memory operations.  
- Improve overlap of computation and communication.

**Q10: Explain how grid-stride loops help in CUDA programming.**  
- Let threads handle more work beyond block size.  
- Useful for dynamically adjusting to data size.

---

## Assignment 5: Mini Project (HPC)

**Q1: What problem statement did you address in your mini-project?**  
- Focused on parallelizing a real-world computational task.  
- Improved performance using OpenMP or CUDA.

**Q2: What parallel programming techniques did you apply?**  
- Used multi-threading (OpenMP) or GPU programming (CUDA).  
- Load distribution and task parallelism were implemented.

**Q3: Which OpenMP/CUDA constructs were most helpful?**  
- OpenMP's `parallel for`, `critical`, and CUDA's thread management.  
- Synchronization constructs ensured correctness.

**Q4: How did you handle load balancing?**  
- Dynamic scheduling in OpenMP or block-based partitioning in CUDA.  
- Adjusted workloads based on observed imbalance.

**Q5: What profiling tools did you use to measure performance?**  
- Tools like `nvprof`, `Nsight`, or `gprof`.  
- Measured runtime, memory, and kernel execution times.

**Q6: How did you optimize memory usage in your project?**  
- Minimized redundant memory allocations.  
- Used shared memory carefully in CUDA.

**Q7: What results did you achieve and how did they compare to the sequential approach?**  
- Achieved significant speedups (2x–10x).  
- Parallel code performed better for large inputs.

**Q8: What were the main bottlenecks you identified?**  
- Memory access bottlenecks and thread divergence.  
- Load imbalance in some cases.

**Q9: If you had more time, what would you improve in your project?**  
- Fine-tune kernel optimizations and memory access patterns.  
- Explore advanced parallelization strategies.

**Q10: How does your project contribute to real-world HPC problems?**  
- Demonstrates scalable solutions.  
- Provides practical acceleration for computation-heavy tasks.

## General HPC Topics

**Q1: What are the applications of Parallel Computing?**  
- Scientific simulations, machine learning, big data analytics.  
- Real-time rendering, weather forecasting, and cryptography.

**Q2: What is the basic working principle of VLIW Processor?**  
- Executes multiple independent instructions in one cycle.  
- Compiler schedules instructions statically before runtime.

**Q3: Explain control structure of Parallel platform in details.**  
- Manages thread creation, synchronization, and communication.  
- Ensures proper execution order and data sharing.

**Q4: Explain basic working principle of Superscalar Processor.**  
- Executes multiple instructions per cycle dynamically.  
- Uses hardware to detect instruction-level parallelism.

**Q5: What are the limitations of Memory System Performance?**  
- Memory bandwidth and latency bottlenecks.  
- Cache misses and limited memory hierarchy size.

**Q6: Explain SIMD, MIMD & SIMT Architecture.**  
- SIMD: Single instruction, multiple data streams.  
- MIMD: Multiple instructions, multiple data streams; SIMT: GPU threads execute same instructions on different data.

**Q7: What are the types of Dataflow Execution models?**  
- Static dataflow and dynamic dataflow models.  
- Static has fixed paths; dynamic adapts execution paths.

**Q8: Write a short note on UMA, NUMA & Level of parallelism.**  
- UMA: Uniform Memory Access, equal memory time for all CPUs.  
- NUMA: Non-Uniform Memory Access, memory time varies; parallelism levels include instruction, thread, and process.

**Q9: Explain cache coherence in multiprocessor system.**  
- Ensures consistency of shared data across caches.  
- Uses protocols like MESI (Modified, Exclusive, Shared, Invalid).

**Q10: Explain N-wide Superscalar Architecture.**  
- Processor can fetch, decode, and execute N instructions per cycle.  
- Improves throughput by parallelizing instruction execution.

**Q11: Explain interconnection network with its type?**  
- Network links multiple processors and memory.  
- Types: Bus-based, crossbar, mesh, hypercube, and torus.

**Q12: Write a short note on Communication Cost In Parallel machine.**  
- Overhead due to data exchange among processors.  
- Includes latency, bandwidth, and synchronization costs.

**Q13: Compare between Write Invalidate and Write Update protocol.**  
- Write Invalidate: Invalidate other caches before writing.  
- Write Update: Broadcast new value to all caches immediately.

---

## Parallel Algorithm Design

**Q1: Explain decomposition, Task & Dependency graph.**  
- Decomposition: Breaking a problem into smaller parts.  
- Dependency graph shows tasks and their inter-dependencies.

**Q2: Explain Granularity, Concurrency & Task interaction.**  
- Granularity: Size of tasks relative to overhead.  
- Concurrency: Degree of parallel execution; Task interaction: communication needs among tasks.

**Q3: Explain decomposition techniques with its types.**  
- Recursive decomposition, data decomposition, exploratory decomposition.  
- Focus on splitting work for parallel execution.

**Q4: What are the characteristics of Task and Interactions?**  
- Tasks have computation and communication needs.  
- Interactions determine synchronization and data sharing.

**Q5: Explain the Mapping techniques in details.**  
- Static and dynamic mapping of tasks to processors.  
- Aims to balance workload and minimize communication.

**Q6: Explain parallel Algorithm Model.**  
- Models include PRAM, BSP, LogP.  
- Abstract the behavior of parallel computations.

**Q7: Explain Thread Organization.**  
- Threads can be organized hierarchically (block, grid).  
- Coordination needed for shared memory and synchronization.

**Q8: Write a short note on IBM CBE.**  
- IBM Cell Broadband Engine: Multi-core processor.  
- Designed for high-performance applications like PS3 gaming.

**Q9: Explain history of GPUs and NVIDIA Tesla GPU.**  
- GPUs evolved from graphics accelerators to GPGPU devices.  
- Tesla GPUs designed for scientific and AI computations.

---

## Communication Operations

**Q1: Explain Broadcast & Reduce operation with help of diagram.**  
- Broadcast sends data from one node to all others.  
- Reduce aggregates data from nodes to one.

**Q2: Explain One-to-all broadcast and reduction on a Ring?**  
- Each node passes data to its neighbor.  
- Takes log(p) steps where p = number of processors.

**Q3: Explain Operation of All to one broadcast & Reduction on a ring?**  
- Reverse of broadcast: nodes send data toward one node.  
- Intermediate nodes sum or combine incoming data.

**Q4: Write a pseudo code for One-to-all broadcast algorithm on hypercube with different cases.**  
- At each dimension, nodes communicate with neighbors.  
- Communication is along differing bit positions.

**Q5: Explain All-to-all broadcast & reduction on Linear array, Mesh and Hypercube topologies.**  
- Linear: Sequential passing of messages.  
- Mesh/Hypercube: Parallel communication reduces steps.

**Q6: Explain Scatter and Gather Operation.**  
- Scatter: Distribute different pieces of data to different nodes.  
- Gather: Collect pieces of data from different nodes.

**Q7: Write short note on Circular shift on Mesh and Hypercube.**  
- Data is rotated among nodes.  
- Useful for load balancing and data redistribution.

**Q8: Explain different approaches of Communication operation.**  
- Direct communication, collective communication.  
- Communication can be synchronous or asynchronous.

**Q9: Explain All-to-all personalized communication.**  
- Every node sends unique message to every other node.  
- Requires heavy communication bandwidth and synchronization.

---

# Deep Learning (DL)

---

## Assignment 1: Linear Regression using Deep Neural Networks

**Q1: What is the architecture of your DNN model for regression?**  
- Input layer, multiple hidden layers, and output layer.  
- Activation functions applied to hidden layers.

**Q2: Why is a deep neural network sometimes used instead of simple linear regression?**  
- DNNs can model complex non-linear relationships.  
- Capture hidden patterns better than linear models.

**Q3: What are the advantages of using ReLU over Sigmoid in hidden layers?**  
- ReLU avoids vanishing gradients problem.  
- Faster convergence during training.

**Q4: What initialization technique was used for weights?**  
- Xavier/Glorot or He initialization.  
- Prevents vanishing or exploding gradients.

**Q5: What happens if learning rate is too high or too low?**  
- Too high: model may diverge.  
- Too low: very slow convergence.

**Q6: What is the role of batch size during training?**  
- Controls number of samples processed before updating weights.  
- Affects training stability and speed.

**Q7: How does regularization help in linear regression models?**  
- Prevents overfitting by penalizing large weights.  
- Techniques include L1, L2 regularization.

**Q8: What is the effect of too many hidden layers on a simple regression problem?**  
- Increases risk of overfitting.  
- Adds unnecessary complexity.

**Q9: How do you validate your model's performance?**  
- Use validation datasets.  
- Monitor loss and accuracy metrics.

**Q10: What are the risks of underfitting in linear regression?**  
- Model cannot capture data trends.  
- Leads to poor predictions and high bias.

---

## Assignment 2: Classification using Deep Neural Networks

**Q1: What is the architecture of your classification DNN?**  
- Input layer, hidden layers, softmax output layer.  
- Fully connected dense layers.

**Q2: How do you encode class labels for multi-class classification?**  
- One-hot encoding or label encoding.  
- Converts categorical labels to numeric vectors.

**Q3: What is softmax activation and how does it work?**  
- Converts logits into probabilities.  
- Outputs sum to 1 across classes.

**Q4: What is categorical cross-entropy loss?**  
- Measures distance between actual and predicted distributions.  
- Used for multi-class classification tasks.

**Q5: How can dropout help during training?**  
- Randomly deactivates neurons during training.  
- Reduces overfitting and improves generalization.

**Q6: How do you handle overfitting in classification models?**  
- Use dropout, regularization, and data augmentation.  
- Early stopping during training.

**Q7: What is the confusion matrix and why is it important?**  
- Matrix showing actual vs predicted classifications.  
- Helps evaluate model performance beyond accuracy.

**Q8: How do you deal with unbalanced datasets?**  
- Oversampling minority class or undersampling majority class.  
- Use weighted loss functions.

**Q9: What is data augmentation and how is it used in classification tasks?**  
- Generate new data by modifying existing samples.  
- Improves model robustness.

**Q10: What are learning rate schedules and why are they important?**  
- Adjust learning rate during training.  
- Helps convergence and avoids overshooting minima.

## Assignment 3: CNN for Fashion MNIST Classification

**Q1: Why are CNNs better for images than fully connected networks?**  
- CNNs capture spatial hierarchies in images.  
- They require fewer parameters and are computationally efficient.

**Q2: What is the size of the filter you used and why?**  
- Typically 3x3 or 5x5 filters.  
- Small filters capture local features effectively.

**Q3: What is feature map in CNN?**  
- Output of applying filters to input images.  
- Represents learned features like edges, textures.

**Q4: Explain the concept of receptive field in CNN.**  
- Region of input image influencing a neuron’s output.  
- Larger receptive fields capture more complex patterns.

**Q5: How does a CNN handle translation invariance in images?**  
- Through convolution and pooling layers.  
- Maintains feature detection despite shifts in input.

**Q6: Why is max pooling preferred over average pooling?**  
- Max pooling captures most important features.  
- Reduces feature dimensions while preserving salient information.

**Q7: What optimizer did you choose and why?**  
- Adam optimizer commonly chosen.  
- It combines benefits of RMSprop and momentum.

**Q8: How do vanishing gradients affect CNNs?**  
- Makes learning slow or stops weight updates.  
- Mostly affects deep networks using saturating activations.

**Q9: What are Batch Normalization layers and how do they help?**  
- Normalize activations within mini-batches.  
- Speed up training and stabilize learning.

**Q10: How did you tune hyperparameters (like learning rate, epochs)?**  
- Used grid search or manual trial-and-error.  
- Monitored validation loss and accuracy.

---

## Assignment 4: Mini Project - Human Face Recognition

**Q1: What preprocessing steps did you apply to the images?**  
- Resizing, normalization, and face alignment.  
- Data augmentation like flipping and brightness adjustment.

**Q2: What CNN architecture or model did you use (custom or pre-trained)?**  
- Used models like FaceNet or custom lightweight CNN.  
- Pre-trained models fine-tuned for better performance.

**Q3: What is face embedding in deep learning?**  
- A vector representation of a face.  
- Used to compare and recognize different faces.

**Q4: How does Triplet Loss function work in face recognition?**  
- Minimizes distance between anchor and positive samples.  
- Maximizes distance between anchor and negative samples.

**Q5: How do you differentiate between classification and verification tasks in face recognition?**  
- Classification: Identify "who" the person is.  
- Verification: Verify if two images are the same person.

**Q6: How did you handle pose and lighting variations?**  
- Used data augmentation and robust model architectures.  
- Applied histogram equalization for lighting issues.

**Q7: What is one-shot learning and where is it useful in face recognition?**  
- Model learns from a single example per class.  
- Useful in few-shot or limited data scenarios.

**Q8: What data augmentation techniques helped your project?**  
- Random crops, rotations, color jittering.  
- Improved model robustness and generalization.

**Q9: How would you deploy the face recognition system into a mobile app?**  
- Convert model to lightweight format (TensorFlow Lite).  
- Optimize inference speed and memory usage.

**Q10: What improvements can be done using transfer learning?**  
- Start from a pre-trained model for faster convergence.  
- Achieve better accuracy with less data.

---

## Basic Deep Learning Concepts

**Q1: What is Batch Size?**  
- Number of training examples used in one iteration.  
- Affects memory usage and convergence speed.

**Q2: What is Dropout?**  
- Regularization technique that randomly deactivates neurons.  
- Helps prevent overfitting.

**Q3: What is RMSprop?**  
- Optimizer that adjusts learning rates based on average of recent gradients.  
- Useful for non-stationary objectives.

**Q4: What is the Softmax Function?**  
- Converts logits into probabilities for classification tasks.  
- Ensures output values are between 0 and 1.

**Q5: What is the ReLU Function?**  
- Activation function defined as f(x) = max(0, x).  
- Helps avoid vanishing gradients and speeds up learning.

---

## More Classification Concepts

**Q1: What is Binary Classification?**  
- Classifying data into one of two categories.  
- Example: Spam vs. not spam detection.

**Q2: What is Binary Cross Entropy?**  
- Loss function for binary classification tasks.  
- Measures the distance between true labels and predictions.

**Q3: What is Validation Split?**  
- Portion of data reserved for evaluating model performance.  
- Helps tune hyperparameters and prevent overfitting.

**Q4: What is the Epoch Cycle?**  
- One complete pass through the entire training dataset.  
- Training usually requires multiple epochs.

**Q5: What is Adam Optimizer?**
- Combines momentum and adaptive learning rates.  
- Popular choice due to fast convergence.

---

## Regression and Neural Networks

**Q1: What is Linear Regression?**  
- Predicts continuous values based on input features.  
- Models linear relationship between variables.

**Q2: What is a Deep Neural Network?**  
- Neural network with multiple hidden layers.  
- Can learn complex representations and patterns.

**Q3: What is the concept of standardization?**  
- Scaling features to have zero mean and unit variance.  
- Improves model convergence and stability.

**Q4: Why split data into train and test?**  
- To evaluate model generalization on unseen data.  
- Prevents overfitting evaluation.

**Q5: Write down applications of Deep Neural Network?**  
- Image recognition, natural language processing, and robotics.  
- Fraud detection, recommendation systems.

---

## MNIST Dataset

**Q1: What is MNIST dataset for classification?**  
- Handwritten digit dataset (0-9).  
- Standard benchmark for image classification models.

**Q2: How many classes are in the MNIST dataset?**  
- 10 classes (digits 0 through 9).  
- Each image corresponds to a single class.

**Q3: What is 784 in MNIST dataset?**  
- 28x28 pixel images flattened into 784 features.  
- Each feature represents pixel intensity.

**Q4: How many epochs are there in MNIST?**  
- Typically 10–50 epochs based on training needs.  
- Depends on convergence speed and overfitting.

**Q5: What are the hardest digits in MNIST?**  
- Digits like 4 and 9 or 3 and 5 are often confused.  
- Variability in handwriting styles causes ambiguity.

---

## Exploratory Data Analysis

**Q1: What do you mean by Exploratory Analysis?**  
- Analyzing datasets to summarize main characteristics.  
- Visual and statistical techniques used.

**Q2: What do you mean by Correlation Matrix?**  
- Table showing correlation coefficients between variables.  
- Identifies relationships between features.

**Q3: What is Conv2D used for?**  
- 2D convolutional layer in CNNs.  
- Applies filters over images to extract features.

---

✅ **All sections fully completed and formatted as you asked!**  
Would you also like me to create a downloadable PDF or Word file of this nicely formatted content for easier reading? 📄  
(Just say: "Yes, make a PDF" or "Yes, make a Word file" if you want!)