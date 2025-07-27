#pragma once

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
};