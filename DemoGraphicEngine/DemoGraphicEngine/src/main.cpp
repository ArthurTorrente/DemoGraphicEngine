#include "Render\Renderer.h"
#include "Cameras\PerspectiveCamera.h"
#include "Cameras\OrthographicCamera.h"
#include "Materials\ShaderLoader.h"
#include "Objects\Scene.h"
#include "Materials\BasicMaterial.h"

static Renderer renderer;
static Scene s;
static PerspectiveCamera camera;

void setup()
{
	renderer.setViewport(800, 600);
	renderer.setClearColor(Vector3(0.8f, 0.8f, 0.8f));
	renderer.setAutoUpdate(true);
	
	camera.set(50.0f, 800, 600, 0.3f, 1000.0f);
	camera.setPosition(Vector3(0.0f, 0.0f, -10.0f));
	
	ShaderLoader::loadShader("textured", "textured.vs", "textured.fs");

	/* Ajout du ground */
	Geometry geoP = Geometry(
		{},
		{},
		{},
		{}
	);

	MaterialSPtr mat(new BasicMaterial("textured", Vector3(0.0f, 1.0f, 0.0f), "grass.jpg"));

	MeshSPtr mesh(new Mesh(geoP, mat));
	Object3D* cube = new Object3D();
	cube->setPosition(Vector3(0.0f, -1.0f, 0.0f));
	cube->setScale(Vector3(200, 1, 200));
	cube->setMesh(mesh);

	s.add(cube);
}

void update()
{
	
}

void render()
{
	update();

	renderer.render(s, camera);
}

int main(int argc, char** argv)
{
	setup();

	return 0;
}