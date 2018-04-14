#pragma once

#include "common.h"

#include "Material.h"
#include "Buffer.h"

#include <vector>


class Mesh
{
public:
	Mesh();
	~Mesh();

	void addBuffer(const std::shared_ptr<Buffer>& buffer, const Material& material);
	size_t getNumBuffers() const;
	const std::shared_ptr<Buffer>& getBuffer(size_t index) const;
	std::shared_ptr<Buffer>& getBuffer(size_t index);
	void draw();

	const Material& getMaterial(size_t index) const;
	Material& getMaterial(size_t index);

private:
	std::vector<shared_ptr<Buffer>> buffersVector;
	std::vector<Material> materialsVector;
};