import numpy as np
from scipy.sparse import csr_matrix

def compute_result(Q, K, V, W):
    # 计算 Q × K^T
    QK = Q.dot(K.T)
    
    # 计算 W · (Q × K^T)
    WQK = QK.multiply(W[:, np.newaxis])
    
    # 计算 (W · (Q × K^T)) × V
    result = WQK.dot(V)
    
    return result

# 读取输入
n, d = map(int, input().split())

# 读取矩阵 Q, K, V
Q = csr_matrix([list(map(int, input().split())) for _ in range(n)])
K = csr_matrix([list(map(int, input().split())) for _ in range(n)])
V = csr_matrix([list(map(int, input().split())) for _ in range(n)])

# 读取向量 W
W = np.array(list(map(int, input().split())))

# 计算结果KO
result = compute_result(Q, K, V, W)

# 输出结果
for row in result.toarray():
    print(' '.join(map(str, row)))import numpy as np

def compute_result(Q, K, V, W):
    # 计算 Q × K^T
    QK = np.dot(Q, K.T)
    
    # 计算 W · (Q × K^T)
    WQK = QK * W[:, np.newaxis]
    
    # 计算 (W · (Q × K^T)) × V
    result = np.dot(WQK, V)
    
    return result

# 读取输入
n, d = map(int, input().split())

# 读取矩阵 Q, K, V
Q = np.array([list(map(int, input().split())) for _ in range(n)])
K = np.array([list(map(int, input().split())) for _ in range(n)])
V = np.array([list(map(int, input().split())) for _ in range(n)])

# 读取向量 W
W = np.array(list(map(int, input().split())))

# 计算结果
result = compute_result(Q, K, V, W)

# 输出结果
for row in result:
    print(' '.join(map(str, row)))