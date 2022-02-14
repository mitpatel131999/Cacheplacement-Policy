# Deep Reinforcement Learning-Based Cache Replacement Policy


### Implementation

The modules are categorized into directory `agents` and `cache`. The `agents` folder contains our implementation of DRL agent and reflex agents, while the `cache` folder contains a cache simulator and its affiliated data loader.

* `CacheAgent.py` contains a series of base classes of cache replacement agents.

* `ReflexAgent.py` contains our implementation of cache agents of hand-crafted replacement policy, e.g. LRU, Random, MRU, etc.

* `DQNAgent.py` contains class `DQNAgent`, a cache agent with DRL-based replacement strategy. `DQNAgent` is based on Deep Q-Network and we employ `tensorflow` to build the MLPs.

* `Cache.py` contains a simulated cache system, acting as the environment for every agent. It not only maintains cache states, but also receives actions from agents and gives feedbacks. Hence, it accepts multiple set of parameters not only to setup the cache system itself, but also to specify the observation features and reward functions.

* `DataLoader.py` contains code to read data from trace and store into data structure.


### Experiments


* To reproduce "Miss Rate compair Cache Capacity", 

* To reproduce "Miss Rate For Input Trace"

## Dataset

i have Attached some sample Trace into data folder i cant not able to attached original due to large size of trace.

data - sample_trace0
     - sample_trace1
     - sample_trace2   