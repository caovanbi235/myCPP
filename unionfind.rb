class UnionFind
  def initialize(n)
    @d = Array.new(n, -1)
  end

  def root(x)
    return x if @d[x] < 0

    @d[x] = root(@d[x])
  end

  def is_same?(x, y)
    root(x) == root(y)
  end

  def unite(x, y)
    x = root(x)
    y = root(y)
    return if x == y

    x, y = y, x if @d[x] > @d[y]
    @d[x] += @d[y]
    @d[y] = x
  end

  def size(x)
    -@d[root(x)]
  end
end