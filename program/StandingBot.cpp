#include "StandingBot.h"
#include "RigidbodyComp.h"
#include "ColliderComp.h"
#include "health.h"
#include "HitBOxRenderComp.h"

std::shared_ptr<GameObject> StandBot::Create()
{
    std::shared_ptr<GameObject> gameObj = std::make_shared<GameObject>();
    gameObj->AddComponent<RigidbodyComp>();
    gameObj->AddComponent<ColliderComp>();
    gameObj->AddComponent<Health>(1);   //  ‰Šú‘Ì—Í‚Í’á‚ß‚É
    gameObj->AddComponent<HitBoxRenderComp>();
    //  ‰ŠúÀ•Wİ’è


    return std::shared_ptr<GameObject>();
}
