from ortools.linear_solver import pywraplp

def lp(objective, constrains, maximize=True):
    solver = pywraplp.Solver.CreateSolver('GLOP')
    get_vars = lambda x: [solver.NumVar(0, solver.infinity(), f'x{var}') for var in range(1,x + 1)]
    vars = get_vars(len(objective))
    for c in constrains:
        constraint = solver.Constraint(c[-1], c[-1])
        for v in range(len(vars)):
            constraint.SetCoefficient(vars[v], c[v])

    objective_func = solver.Objective()
    for v in range(len(vars)):
        objective_func.SetCoefficient(vars[v], objective[v])
    if maximize:
        objective_func.SetMaximization()
    else: objective_func.SetMinimization()

    solver.Solve()
    print('Number of variables =', solver.NumVariables())
    print('Number of constraints =', solver.NumConstraints())
    print('Solution:')
    opt_solution = 0 
    for v in range(len(vars)):
        print(f'x{v + 1}: {vars[v].solution_value()}')
        opt_solution += vars[v].solution_value() * objective[v]
    print('Optimal objective value =', opt_solution)

lp(
    objective=(5,1,4,4,0,0,0),
    constrains=[
        [4,1,3,3,1,0,0,17],
        [1,0,1,1,0,1,0,4],
        [2,1,2,3,0,0,1,10]
    ]
)

lp(
    objective = [1,2,1,0,0,0],
    constrains = [
        [1,1,2,1,0,0,4],
        [1,0,3,0,1,0,4],
        [1,1,3,0,0,1,7]
    ]
)

lp(
    objective=[1,2,-1,0,0,0],
    constrains=[
        [2,-2,1,1,0,0,10],
        [-3,-2,2,0,1,0,9],
        [1,-4,1,0,0,1,10]
    ]
)

lp(
    objective=[1,3,-1],
    constrains=[
        [-1,3,0,2],
        [7,-5,2,-1],
        [1,11,-10,1]
    ]
)

lp(
    objective=[-3,0,1,0],
    constrains=[
        [1,1,1,1,14],
        [-2,-1,-1,3,-10],
        [0,16,1,1, 9]
    ]
)