def tree(label, branches = []):
    for b in branches:
        assert is_tree(b), 'branches must be trees'
    return [label] + list(branches)

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    for b in branches(tree):
        if not is_tree(b):
            return False
    return True

def label(tree):
    #assert is_tree(tree), 'only trees have label'
    if is_tree(tree):
        return tree[0]
    return

def branches(tree):
    #assert is_tree(tree), 'only trees have branches'
    return tree[1:]

def is_leaf(tree):
    assert is_tree(tree), 'only tree without branches can be leaf'
    return len(tree) == 1

def is_min_heap(tree):
    if len(tree) == 1:
        return label(tree)
    else:
        for b in branches(tree):
            if not is_min_heap(b):
                return False
    return True

def largest_product_paths(tree):
    if not is_tree(tree):
        return False
    elif len(tree) == 1:
        return label(tree)
    return max([label(tree)*largest_product_paths(b) for b in branches(tree)])

'''
def max_tree(t):
    if is_leaf(t):
        return tree(label(t))
    else:
        new_branches = [max_tree(b) for b in branches(t)]
        new_label = max([label(t)] + [label(s) for s in new_branches])
        return tree(new_label, new_branches)
'''
'''
#root(tree) is not defined
def root(tree):
    #???
'''

def level_order(tree):
    if not tree:
        return []
    current_level, next_level = [label(tree)], [tree]
    while next_level:
        find_next = []
        for b in next_level:
            find_next.extend(branches(b))
        next_level = find_next
        current_level.extend([label(t) for t in next_level])
    return current_level

def all_paths(t):
    if is_leaf(t):
        return [[label(t)]]
    else:
        total = []
        for b in branches(t):
            for path in all_paths(b):
                total.append([label(t)] + path)
        return total


