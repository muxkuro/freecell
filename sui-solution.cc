#include "search-strategies.h"
#include <algorithm>
#include <stack>
#include <queue>

std::vector<SearchAction> BreadthFirstSearch::solve(const SearchState &init_state) {

    std::queue<SearchState> states;
    std::stack<SearchState> previousStates;
    std::vector<SearchState> visited;
    std::vector<SearchAction> solution;

    //set current working state
    SearchState working_state(init_state);

    //pushing working state to queue
    states.push(working_state);

    //loop until all there are no states
    while (!states.empty()) {
        //delete current state
        states.pop();

        //push current state to visited
        visited.push_back(working_state);

        //check for all posible actions from this state
        auto actions = working_state.actions();

        //we will return to this state because it still have actions 
        if (actions.size() > 1) {
            previousStates.push(working_state);
        }

        //if there are no actions available return the previous state
        if (actions.size() == 0) {
            if (!previousStates.empty()) {
                SearchState temp_state = previousStates.top();
                previousStates.pop();
                states.push(temp_state);
            }
        }

        //loop for all possible actions from current state
        for (auto i = 0; i != actions.size(); i++) {
            //check if we have this action in solution already
            auto findAction{ std::find(solution.begin(), solution.end(), actions[i]) };
            //if not push it to the solution, execute action on current state, push new state to the queue
            if (findAction == solution.end()) {
                solution.push_back(actions[i]);
                working_state = actions[i].execute(working_state);
                states.push(working_state);

                //if it's a solution, return it
                if (working_state.isFinal()) {
                    return solution;
                }

                break;
            }
        }
    }

	return {};
}

std::vector<SearchAction> DepthFirstSearch::solve(const SearchState& init_state) {
    std::stack<SearchState> states;
    std::stack<SearchState> previousStates;
    std::vector<SearchState> visited;
    std::vector<SearchAction> solution;

    //set current working state
    SearchState working_state(init_state);

    //pushing working state to stack
    states.push(working_state);

    //loop until all there are no states
    while (!states.empty()) {
        //delete current state
        states.pop();

        //push current state to visited
        visited.push_back(working_state);

        //check for all posible actions from this state
        auto actions = working_state.actions();

        //we will return to this state because it still have actions 
        if(actions.size() > 1){
            previousStates.push(working_state);
        }

        //if there are no actions available return the previous state
        if (actions.size() == 0) {
            if (!previousStates.empty()) {
                SearchState temp_state = previousStates.top();
                previousStates.pop();
                states.push(temp_state);
            }
        }

        //loop for all possible actions from current state
        for (auto i = 0; i != actions.size(); i++) {
            //check if we have this action in solution already
            auto findAction{ std::find(solution.begin(), solution.end(), actions[i]) };
            //if not push it to the solution, execute action on current state, push new state to the stack
            if (findAction == solution.end()) {
                solution.push_back(actions[i]);
                working_state = actions[i].execute(working_state);
                states.push(working_state);

                //if it's a solution, return it
                if (working_state.isFinal()) {
                    return solution;
                }

                break;
            }
        }
    }

    return {};
}

double StudentHeuristic::distanceLowerBound(const GameState &state) const {
    return 0;
}

std::vector<SearchAction> AStarSearch::solve(const SearchState &init_state) {
	return {};
}
