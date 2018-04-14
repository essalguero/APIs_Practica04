#include "Mesh.h"
#include "State.h"


Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

void Mesh::addBuffer(const std::shared_ptr<Buffer>& buffer, const Material& material)
{
	buffersVector.push_back(buffer);

	materialsVector.push_back(material);
}

size_t Mesh::getNumBuffers() const
{
	return buffersVector.size();
}

const std::shared_ptr<Buffer>& Mesh::getBuffer(size_t index) const
{
	shared_ptr<Buffer> pointer = nullptr;

	if (index >= 0 && index < buffersVector.size())
		return buffersVector.at(index);

	return pointer;
}

std::shared_ptr<Buffer>& Mesh::getBuffer(size_t index)
{
	shared_ptr<Buffer> pointer = nullptr;

	if (index >= 0 && index < buffersVector.size())
		return buffersVector.at(index);

	return pointer;
}

const Material& Mesh::getMaterial(size_t index) const
{
	return materialsVector.at(index);
}

Material& Mesh::getMaterial(size_t index)
{
	return materialsVector.at(index);
}


void Mesh::draw()
{
	for (int i = 0; i < buffersVector.size(); ++i)
	{
		shared_ptr<Shader> shader = materialsVector.at(i).getShader();

		//Activate the shader
		shader->use();

		// Call the material prepare
		materialsVector.at(i).prepare();

		// Draw the buffer using the shader
		buffersVector.at(i)->draw(shader);
		
	}
}

static std::shared_ptr<Mesh> load(
	const char* filename,
	const std::shared_ptr<Shader>& shader = nullptr)
{
	shared_ptr<Mesh> mesh;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename);
	if (result) {
		// Cargado correctamente, podemos analizar su contenido ...
	}
	else {
		// No se ha podido cargar
		std::cout << result.description() << std::endl;
		return nullptr;
	}
}