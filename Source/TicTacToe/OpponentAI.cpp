// Fill out your copyright notice in the Description page of Project Settings.


#include "OpponentAI.h"


bool UOpponentAI::HasMovesLeft(USpaceState::EActivePlayer Spaces[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			return Spaces[i][j] == USpaceState::EActivePlayer::None;
		}
	}
	return false; 
}

int UOpponentAI::EvaluateBoard(USpaceState::EActivePlayer Spaces[3][3])
{
	// Checking Horizontal
	for(int Row = 0; Row < 3; Row++)
	{
		if(Spaces[Row][0] == Spaces[Row][1] &&
			Spaces[Row][1] == Spaces[Row][2])
		{
			if(Spaces[Row][0] == USpaceState::EActivePlayer::X)
				return +10;
			else if(Spaces[Row][0] == USpaceState::EActivePlayer::O)
				return -10;
		}
	}

	// Check Vertical
	for(int Column = 0; Column < 3; Column++)
	{
		if(Spaces[0][Column] == Spaces[1][Column] &&
			Spaces[1][Column] == Spaces[2][Column])
		{
			if(Spaces[0][Column] == USpaceState::EActivePlayer::X)
				return +10;
			else if(Spaces[0][Column] == USpaceState::EActivePlayer::O)
				return -10;
		}
	}
	
	// Check Diagonal Top Left -> Bottom Right
	if(Spaces[0][0] == Spaces[1][1] &&
		Spaces[1][1] == Spaces[2][2])
	{
		if(Spaces[0][0] == USpaceState::EActivePlayer::X)
			return +10;
		else if(Spaces[0][0] == USpaceState::EActivePlayer::O)
			return -10;
	}

	// Check Diagonal Bottom Left -> Top Right
	if(Spaces[0][2] == Spaces[1][1] &&
		Spaces[1][1] == Spaces[2][0])
	{
		if(Spaces[0][2] == USpaceState::EActivePlayer::X)
			return +10;
		else if(Spaces[0][2] == USpaceState::EActivePlayer::O)
			return -10;
	}
	
	return 0;
	
}

int UOpponentAI::MiniMax(USpaceState::EActivePlayer Spaces[3][3], int Depth, bool bIsMax)
{
	
	int Score = EvaluateBoard(Spaces);

	// If the Maximizer has won the game, return their evaluated score
	if(Score == 10)
		return Score;

	// if the Minimizer has won the game, return their evaluated score
	if(Score == -10)
		return Score;

	// If there are no more moves and no winner then it's a tie
	if(HasMovesLeft(Spaces) == false) // !
		return 0;

	// If Maximizer's turn
	if(bIsMax == true)
	{
		
		int Best = -1000;

		// Traverse all the cells
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				// Check if cell is empty
				if(Spaces[i][j] == USpaceState::EActivePlayer::None)
				{
					// Make the move
					Spaces[i][j] = USpaceState::EActivePlayer::X;

					// Call MiniMax recursively and choose the maximum value
					Best = std::max(Best, MiniMax(Spaces, Depth + 1, !bIsMax));

					// Undo the move
					Spaces[i][j] = USpaceState::EActivePlayer::None;
				}
			}
		}
		return Best;
	}
	else
	{

		int Best = 1000;

		// Traverse all cells
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				// Check if the cell is empty
				if(Spaces[i][j] == USpaceState::EActivePlayer::None)
				{
					// Make the move
					Spaces[i][j] = USpaceState::EActivePlayer::O;

					// Call the Minimax recursively and choose the minimum value
					 Best = std::min(Best, MiniMax(Spaces, Depth + 1, !bIsMax));
					
					// Undo the move
					Spaces[i][j] = USpaceState::EActivePlayer::None;
				}
			}
		}
		return Best;
	}
	
}

 FMove UOpponentAI::FindBestMove(USpaceState::EActivePlayer Spaces[3][3])
{

	int BestValue = -1000;
	FMove BestMove;
	BestMove.Row = -1;
	BestMove.Column = -1;

	// Traverse all cells, evaluate MiniMax function for all empty cells and return cell with optimal value.
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			// Check if the cell is empty.
			if(Spaces[i][j] == USpaceState::EActivePlayer::None)
			{
				// Make the move.
				Spaces[i][j] = USpaceState::EActivePlayer::X; 

				// Compute evaluation function for this move.
				int MoveValue = MiniMax(Spaces, 0, false); 
				
				// Undo the move
				Spaces[i][j] = USpaceState::EActivePlayer::None;

				// If the value of the current move is more then the best value update best.
				if(MoveValue > BestValue)
				{
					BestMove.Row = i;
					BestMove.Column = j;
					BestValue = MoveValue;
				}
			}
		}
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("NextMove Row: %i Column: %i"), BestMove.Row, BestMove.Column));
	
	return BestMove;
	
}

