class PriorityQueue
  def initialize
    @heap = []
  end

  def push(item, priority)
    @heap << [item, priority]
    bubble_up_iterative(@heap.size - 1)
    self
  end

  def pop
    return if @heap.empty?

    swap(0, @heap.size - 1)
    min = @heap.pop
    bubble_down_iterative(0) unless @heap.empty?
    min
  end

  def peek
    @heap[0]
  end

  def empty?
    @heap.empty?
  end

  def size
    @heap.size
  end

  private

  def bubble_up_iterative(index)
    while index > 0
      parent_index = (index - 1) / 2
      break if @heap[parent_index][1] <= @heap[index][1]

      swap(index, parent_index)
      index = parent_index
    end
  end

  def bubble_down_iterative(index)
    while true
      min_index = index
      left = 2 * index + 1
      right = left + 1

      min_index = left if left < @heap.size && @heap[left][1] < @heap[min_index][1]
      min_index = right if right < @heap.size && @heap[right][1] < @heap[min_index][1]

      break if min_index == index

      swap(index, min_index)
      index = min_index
    end
  end

  def swap(i, j)
    @heap[i], @heap[j] = @heap[j], @heap[i]
  end
end