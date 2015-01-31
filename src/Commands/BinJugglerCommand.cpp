#include "BinJugglerCommand.h"

BinJugglerCommand::BinJugglerCommand(int cylinder, bool state)
{
	m_cylinder = cylinder;
	m_state = state;
}

void BinJugglerCommand::Initialize()
{
	Robot::m_binJuggler->loadSelection(m_cylinder, m_state);
}

void BinJugglerCommand::Execute()
{

}

bool BinJugglerCommand::IsFinished()
{
	return false;
}

void BinJugglerCommand::End()
{

}

void BinJugglerCommand::Interrupted()
{

}
