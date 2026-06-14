#pragma once
#include "Cinematica.h"

Cinematica^ setupCinNvl1Inicio() {
	Cinematica^ cin = gcnew Cinematica();

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8""
	}), gcnew Bitmap("sprites\\cinematicas\\inicionvl1.jpeg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8"“Remontar ese río era como viajar de regreso",
		u8" a los primeros orígenes del mundo,   cuando",
		u8" la vegetación se  desbordaba  sobre la tie-",
		u8" rra y los  grandes  árboles eran reyes.  Un",
		u8" curso de agua vacío, un  gran silencio, una",
		u8" selva impenetrable. El aire era cálido, es-",
		u8" peso, pesado, lento. No había alegría en el",
		u8" fulgor del sol. [...] Y esa quietud  de  la",
		u8" vida no se parecía  en absoluto a  la  paz.",
		u8" Era laquietud de una fuerza implacable  que",
		u8" se cernía sobre una intención inescrutable.",
		u8" Te miraba con un aire vengativo.”",
		u8"          — Joseph Conrad, Heart of Darkness",
		}), gcnew Bitmap("sprites\\cinematicas\\heartofdarkness.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Cuando viajé por primera vez a través del Río",
			u8" Ene, entendí por qué los nativos dicen que los",
			u8" ríos tienen alma. Turbulencia.     Estruendo.",
			u8" Desasosiego. Extenuación. Era como si la Pro-",
			u8" videncia, a través de la voz de la naturaleza,",
			u8" estuviese recitando la elegía de la defunción",
			u8" de sus guardianes. Estuve así por tres largos",
			u8" días, acompañado, gracias a Dios, por un re-",
			u8" mero, el único que aceptó llevarme a Kametsa",
			u8" Pampa. Tres días de un calor sofocante, de",
			u8" mosquitos zumbando en el oído, y de sentir en",
			u8" carne propia la Ira de Dios... un concepto no",
			u8" ajeno ni a los nativos ni a los exploradores",
			u8" españoles que penetraron estas tierras hace",
			u8" cinco centurias."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide1.jpg"));


	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Yo no soy tan diferente a ellos. Yo también",
			u8" estoy movido por la codicia... de conocimien-",
			u8" to. Ansias por descubrir, no solo la verde",
			u8" beldad de Natura, sino de aquello que no se",
			u8" cuenta con palabras.",
			u8"",
			u8" De lo que todos parlan con laudable actitud,",
			u8" de aquello que todos buscan pero que pocos",
			u8" defienden: la Verdad (sí, con mayúscula)..."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide2.jpg"));


	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Llamádme Mateo. Soy periodista de profesión.",
			u8" Doce años en la carrera, siete de los cuales",
			u8" pasé en Crónica Viva.",
			u8" Ah, Crónica Viva. Famosa en su inexistente",
			u8" fama e infame por su crudo impacto. Una re-",
			u8" vista cualquiera que no resalta en nada: ni",
			u8" en la verborrea de sus escritores ni en el",
			u8" carisma de sus presentadores... salvo por el",
			u8" único aspecto que de verdad importa: su in-",
			u8" quebrantable monomanía por la VERDAD."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide3.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" He viajado por toda la patria. He seguido los",
			u8" rastros de organizaciones criminales en Lima,",
			u8" he cubierto derrames mineros en Pasco, desa-",
			u8" pariciones en el VRAEM... siempre armado con",
			u8" nada más que una grabadora, una cámara y mi",
			u8" verboso ser. Pero nunca, nunca... me he aden-",
			u8" trado tanto en la selva..."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide4.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Lo que me trajo aquí: fotografías satelita-",
			u8" les. Obscuridad sobre el manto verde de la",
			u8" Amazonía. Y un dato: en los últimos dos años,",
			u8" ningún periodista ha llegado a Kametsa Pampa.",
			u8" Los que lo intentaron cambiaron misteriosa-",
			u8" mente su rumbo en el camino, o regresaban con",
			u8" una lacónica explicación de su laxitud."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide5.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Antes de partir, mi editor me dijo: «Consigue",
			u8" la historia. Pero no te metas en problemas».",
			u8" Parece que se le olvidó que nosotros somos EL",
			u8" problema..."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide6.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" En la noche del tercer día, paramos en el",
			u8" sendero que conducía hacia Puerto Esperanza,",
			u8" nombre en castellano cuya peculiaridad no",
			u8" podía ignorar. El remero, sin embargo, se",
			u8" negó a llevarme, mas accedió a acompañarme a",
			u8" pasar la última noche conmigo. Al amanecer,",
			u8" y antes de partir, me suplicó que sea cauto.",
			u8" Y así, sin darme más explicaciones, se mar-",
			u8" chó río abajo."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide7.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" El sendero había sido obscurecido por la",
			u8" gruesa neblina. No había más ruido que mi",
			u8" propia respiración, el sonido del agua flu-",
			u8" yendo y algunos monos aulladores que chilla-",
			u8" ban en la distancia. La selva me miraba con",
			u8" un aire vengativo."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide8.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Y me di cuenta que no estaba solo. Dos hom-",
			u8" bres, jóvenes, robustos, se pusieron en cada",
			u8" uno de mis costados. Intenté mantener la",
			u8" calma... pero, ¿cómo no hacer la tan obvia",
			u8" conexión entre datos supuestamente tan dis-",
			u8" pares? Los periodistas que cambiaban su",
			u8" rumbo, los murmullos del remero, y esta ex-",
			u8" traña presencia..."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide9.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" HOMBRE 1: ¿Periodista, eh? Te estábamos es-",
			u8" perando.",
			u8"",
			u8" Una mísera noche y ya había sido marcado.",
			u8" ¡Cómo me sonreía el sino! Hice lo que pude",
			u8" para contener una risilla histérica. Era",
			u8" todo tan absurdo, pero a la vez tan obvio",
			u8" que me sentí el hombre más estúpido del",
			u8" mundo.",
			u8"",
			u8" HOMBRE 2: El monte es grande, forastero.",
			u8" Fácil perderse. Y nadie va a ayudarte."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide10.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" El primero se acercó más. Pude oler el fan-",
			u8" tasma del tabaco en su aliento y las manchas",
			u8" de aceite en su torso. Tenía en su faz una",
			u8" sonrisa burlona, y sus gestos estaban man-",
			u8" chados hasta el tuétano con una parsimonia",
			u8" agobiante. Era como si fuese un profesor",
			u8" lidiando con un lerdo infante."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide11.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" HOMBRE 1: Mira, te voy a dar un consejo.",
			u8" Tú tomas tus fotos bonitas, escribes tu",
			u8" nota y te largas río abajo. En dos días",
			u8" llegas a Satipo. En dos más, a Lima...",
			u8" Piensa en tu familia. En tu carrera. Y en",
			u8" el brillante futuro que tienes por delante.",
			u8" Aquí no hay historia, solo gente que no",
			u8" quiere hablar con extraños.",
			u8"",
			u8" ¿Entendiste?"
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide11.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" El segundo hombre no se molestó en hablar,",
			u8" respondiendo con una carcajada a pulmón",
			u8" junto a una peculiar mirada: dudando si",
			u8" verme con la pena que uno siente al ver a",
			u8" un desquiciado, o con la molestia que inva-",
			u8" de cuando ves a un insecto."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slide11.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" No les respondí. Consentir era fútil. Hablar",
			u8" era darles bagatelas. Y el silencio...",
			u8" era temerario...",
			u8"",
			u8" No se marcharon. Simplemente caminaron",
			u8" algunos pasos sendero arriba y se quedaron",
			u8" allí, observando, y esperando.",
			u8"",
			u8" ¿A qué? ¿A que abriera la boca? ¿O buscaban",
			u8" la razón para que su florida verborrea evo-",
			u8" lucione al poco elegante arte de los puños?"
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1slidefinal.jpg"));


	return cin;
}

Cinematica^ setupCinNvl1Final() {
	Cinematica^ cin = gcnew Cinematica();

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8""
	}), gcnew Bitmap("sprites\\cinematicas\\finnvl1.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" La brisa sopla, meciendo los árboles, los",
			u8" arbustos y la maleza. Un manto dorado cubre",
			u8" el pasto donde estoy reposando. Es el cre-",
			u8" púsculo. En menos de una hora, el sol se",
			u8" esconderá completamente, abriendo paso a la",
			u8" luna, cumpliendo la eterna pero necesaria",
			u8" dualidad entre la luz y la oscuridad. Miro",
			u8" al horizonte. Siento que la naturaleza me",
			u8" susurra, me atrapa, me seduce. ¿Y si de ver-",
			u8" dad las plantas tienen alma? Me pregunto,",
			u8" mientras fumo un poco del tabaco que el",
			u8" Abuelo Tomás me dio esa misma mañana."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide1.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Ahí es cuando siento una presencia detrás",
			u8" de mí. Antes de que pueda reaccionar, siento",
			u8" una mano en mi hombro. Alzo la mirada. Re-",
			u8" conozco inmediatamente ese rostro. Es Wil-",
			u8" mer. Está más cansado que cuando lo vi por",
			u8" primera vez, esa misma mañana, pero hay una",
			u8" extrañeza en su faz. Un sutil, traicionero,",
			u8" rayo de esperanza. Se me queda observando",
			u8" por un largo intervalo, hasta que rompe el",
			u8" silencio."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide2.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" WILMER: Le caíste bien a Doña Rosa. Mamá",
			u8" Clara preguntó por ti. Don Tomás dice que",
			u8" sabes escuchar. Estoy sorprendido...",
			u8"",
			u8" Eso es raro en un forastero."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide2.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Hace una pausa, dudando si cruzar el umbral",
			u8" del que jamás regresará.",
			u8"",
			u8" WILMER: El Abuelo Evaristo quiere verte."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide3.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Caminamos un largo sendero en total silen-",
			u8" cio. No es la lúgubre carencia de sonido de",
			u8" las interminables noches de viaje. Es algo",
			u8" diferente. Lleno en su flaqueza. Los últimos",
			u8" sonidos distantes, los murmullos, los gri-",
			u8" tos, la indiscutible VIDA de un pueblo que",
			u8" se niega a fenecer, desaparecen a nuestras",
			u8" espaldas. Y la naturaleza, tan atenta, pa-",
			u8" rece notar este hecho."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide4.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" WILMER: Don Evaristo es el líder del pueblo.",
			u8" Él es el último que lo recuerda todo. Nues-",
			u8" tra fundación. Los nombres de nuestros an-",
			u8" cestros. Los lugares donde solíamos pescar",
			u8" y cosechar nuestros cultivos. Los cantos",
			u8" tradicionales y los rituales que abundaban",
			u8" antes que llegaran los madereros.",
			u8"",
			u8" Por eso es que le tenemos tanto respeto.",
			u8" Porque es la personificación del pueblo. Si",
			u8" él se va, todo el pueblo se va con él."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide5.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" MATEO: ¿Y por qué no se lo enseña todo lo",
			u8" que sabe a la juventud? Al fin y al cabo,",
			u8" alguna vez él también fue joven. Y no hay",
			u8" regalo más grande que dar la responsabili-",
			u8" dad de la supervivencia de un pueblo a las",
			u8" futuras generaciones."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide6.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" WILMER: Antes había comunión con la natura-",
			u8" leza. El hombre y la tierra eran uno. No se",
			u8" parasitaba. Se daba y se recibía. Y fue así",
			u8" por siglos. Y gracias a ello, es que nuestro",
			u8" pueblo se mantuvo saludable.",
			u8"",
			u8" Pero con los madereros, eso se rompió. Los",
			u8" jóvenes nacieron desarraigados. Rechazan la",
			u8" tierra, porque la tierra, ellos creen, los",
			u8" rechazó. Y ellos se van. O trabajan para",
			u8" ellos. O simplemente mueren muy jóvenes.",
			u8"",
			u8" Y los que quedamos... estamos cansados."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide6.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" El sendero desemboca en un claro. Allí, so-",
			u8" litaria, hay una ceiba gigante. Mi vida en",
			u8" Lima pasa por mi mente al verla. Es tan al-",
			u8" ta como esos edificios residenciales que",
			u8" abundan en San Isidro o en Jesús María. Y",
			u8" es tan ancha que se necesitaría más de cinco",
			u8" hombres para abrazarla."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide7.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Al costado, una cabaña de madera. Y un te-",
			u8" cho de palma. Es pequeña, pero bien cuida-",
			u8" da. Y mentiría si digo que no sentí un esta-",
			u8" llido de emociones al verla. Tiene ese aire",
			u8" peculiar de los lugares que sienten, que",
			u8" recuerdan millares de recuerdos, de cuitas,",
			u8" de alegrías."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide7.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" De la chimenea sale un humo blanco. Y lo",
			u8" puedo distinguir. Huele a tabaco. Quizás",
			u8" sea el mismo que me dio Don Tomás, y el cual",
			u8" aún no había acabado."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide7.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" WILMER: Esta parte es tuya, Mateo. Yo no",
			u8" puedo entrar contigo.",
			u8"",
			u8" Su mirada, furtiva, logra fijarse en mi",
			u8" ser. Hay una advertencia en sus ojos."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide7.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" WILMER: No le mientas. No le prometas nada",
			u8" que no vayas a cumplir. Y sobre todo, escu-",
			u8" cha. Es lo que más nos falta a todos, des-",
			u8" pués de todo."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide7.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Wilmer se aparta. Estoy completamente solo",
			u8" ante el peligroso umbral. ¿Pero qué es mi",
			u8" vida sin este tipo de exaltación? A lo lar-",
			u8" go de mi vida, he aprendido a vivir peli-",
			u8" grosamente. Y es lo que me ha llevado hasta",
			u8" donde estoy.",
			u8"",
			u8" Pero nunca, nunca, me había sentido tan...",
			u8" débil. Sabía cómo controlar mis nervios",
			u8" ante las amenazas, las extorsiones y los",
			u8" ataques bajos. Pero nunca había lidiado",
			u8" con mi propia incertidumbre..."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide8.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" Volteo la cabeza. Wilmer ha desaparecido.",
			u8" Recuerdo los anteriores reportajes. Aquel",
			u8" reporte de la minería ilegal en Pasco, y",
			u8" del cual volví con una historia indiscu-",
			u8" tible, y después del cual me llovieron",
			u8" muchos agradecimientos en forma de casqui-",
			u8" llos de bala en mi puerta.",
			u8"",
			u8" Ya estaba acostumbrado al riesgo... Y vol-",
			u8" ví a confirmar que este riesgo era dife-",
			u8" rente. Pensé: ¿Cuál es la diferencia?"
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide8.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" La respuesta estaba alrededor, detrás, y",
			u8" frente mío. El costo social. La admiración",
			u8" genuina y el asombro causado por la tena-",
			u8" cidad de un pueblo, de la sabiduría de sus",
			u8" líderes... y un pesar ahogante por el su-",
			u8" frimiento de Kipatsi..."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide8.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" No lo pienso más. Empujo la puerta, la cual",
			u8" había sido dejada convenientemente entre-",
			u8" abierta. Las bisagras gimen ante mi inva-",
			u8" sión."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide9.jpg"));

	cin->agregarSlide(gcnew List<String^>(gcnew array<String^> {
		u8" EVARISTO: Pasa, periodista. Te estábamos",
			u8" esperando.",
			u8"",
			u8" No lo logro ver. Pero sé que está ahí.",
			u8" Que... ellos están allí."
	}), gcnew Bitmap("sprites\\cinematicas\\nvl1fslide9.jpg"));

	return cin;
}