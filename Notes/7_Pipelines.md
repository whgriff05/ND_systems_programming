# Pipelines

## The pipeline is like an assembly line
Stage 1: Gather and read text/data

Stage 2: Filter and select text/data

Stage 3: Aggregate and count text/data

## Why do we use pipelines?
Each task can be optimized for that specific task (i.e. filtering is super fast at filtering specific patterns)

Allows for __concurrency__, where different processes can be scheduled to operate basically at the same time, and even __parallel computing__, where processes __do__ run at the same time