#include "DiveWireController.h"
#include "GameObject.h"
#include "PlayerStateController.h"

/// <summary>
/// ”­Ë‰Â”\ó‘Ô‚Ì”»’è‚Æ“ü—Í‚Ì”»’èADiveWire‚Ì—LŒø‰»
/// </summary>
void DiveWireController::Update() {
	auto state = GetGameObj()->GetComponent<StateController>();
	if (!state)return;
	if (!state->CanDiveWire()) return;

	
}