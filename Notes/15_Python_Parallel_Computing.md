# Parallel Computing in Python

## Concurrency vs Parallelism
__Concurrency__ is the composition of __independent__ computations
- Concerned about structure/division of labor

__Parallelism__ is the simultaneous execution of (possibly related) computations
- Concerned with resources

Concurrency provides a way to structure a solution to solve a problem that may or may not be parallelizable

## Pitfalls of Concurrency
__race condition__ - multiple tasks compete for the same resource in an unpredictable manner

__deadlock__ - multiple tasks are stuck waiting for each other

## Hallmarks of Concurrency
__embarrasingly parallel__ - when a problem exhibits natural concurrency (they should obviously be completed in parallel)
- little or no dependency between tasks
- little or no need to communicate between tasks

__task parallelism__ - Generators support these types of problems
- concurrent execution of different tasks on the same/different datasets
- different tasks must communicate/coordinate with each other

__data parallelism__ - Functional Programming maps well to problems with this characteristic
- concurrent execution of the __same__ task on the elements of a dataset
- the dataset usually exhibits data independence (the elements can be processed independently)


